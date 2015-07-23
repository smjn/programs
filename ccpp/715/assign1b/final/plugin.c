/*-----------------------------------------------------------------------------
 *  "gcc-plugin.h" must be the FIRST file to be included 
 *-----------------------------------------------------------------------------*/
#include "gcc-plugin.h"

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "diagnostic.h"
#include "tree-flow.h"
#include "tree-pass.h"
#include "toplev.h"
#include "gimple-pretty-print.h"
#include "cgraph.h"
#include "coretypes.h"
#include "tree.h"
#include "diagnostic.h"
#include "timevar.h"
#include "alloc-pool.h"
#include "params.h"
#include "ggc.h"
#include "vec.h"

/*-----------------------------------------------------------------------------
 *  Each plugin MUST define this global int to assert compatibility with GPL; 
 *  else the compiler throws a fatal error 
 *-----------------------------------------------------------------------------*/
int plugin_is_GPL_compatible;
static unsigned int execute_pass_plugin(void);
/*-----------------------------------------------------------------------------
 *  Structure of the pass we want to insert, identical to a regular ipa pass
 *-----------------------------------------------------------------------------*/
struct gimple_opt_pass pass_plugin = { { GIMPLE_PASS, "ast", /*  name */
0, /*  gate */
execute_pass_plugin, /*  execute */
NULL, /*  sub */
NULL, /*  next */
0, /*  static pass number */
TV_INTEGRATION, /*  tv_id */
0, /*  properties required */
0, /*  properties provided */
0, /*  properties destroyed */
0, /*  todo_flags start */
0 /*  todo_flags end */
} };

/*-----------------------------------------------------------------------------
 *  This structure provides the information about inserting the pass in the
 *  pass manager. 
 *-----------------------------------------------------------------------------*/
struct register_pass_info pass_info = { &(pass_plugin.pass), /* Address of new pass, here, the 'struct
 opt_pass' field of 'simple_ipa_opt_pass'
 defined above */
"cfg", /* Name of the reference pass for hooking up
 the new pass.  */
0, /* Insert the pass at the specified instance
 number of the reference pass. Do it for
 every instance if it is 0. */
PASS_POS_INSERT_AFTER /* how to insert the new pass: before,
 after, or replace. Here we are inserting
 a pass names 'plug' after the pass named
 'pta' */
};

/*-----------------------------------------------------------------------------
 *  plugin_init is the first function to be called after the plugin is loaded
 *-----------------------------------------------------------------------------*/
int plugin_init(struct plugin_name_args *plugin_info,
		struct plugin_gcc_version *version) {

	/*-----------------------------------------------------------------------------
	 * Plugins are activiated using this callback
	 *-----------------------------------------------------------------------------*/
	register_callback(plugin_info->base_name, /* char *name: Plugin name, could be any
	 name. plugin_info->base_name gives this
	 filename */
	PLUGIN_PASS_MANAGER_SETUP, /* int event: The event code. Here, setting
	 up a new pass */
	NULL, /* The function that handles event */
	&pass_info); /* plugin specific data */

	return 0;
}

enum var_mnemonic {
	VARIABLE, ARTIFICIAL, CONSTANT, NULL_T, UNARY_T
};

typedef struct var_t {
	enum var_mnemonic varType;
	char val[20];
} var_t;

typedef struct sNode {
	//int key; //lhs of expression, (variable name), for normal variable -1
	int bb_id;
	var_t lop;
	enum tree_code opType; //operator being used (add,mul,div,sub,lshift,rshift)
	var_t ropL; //operand1 of operator opType
	var_t ropR; //operand2 of operator opType
	char temp[100];
	int toResolve;
	bool resolved;
	struct sNode *next;
} dNode;

static void initVar(var_t *var) {
	var->varType = VARIABLE;
	var->val[0] = '\0';

}
static void init(dNode *node, int bb_id) {
	node->bb_id = bb_id;
	initVar(&(node->lop));
	initVar(&(node->ropL));
	initVar(&(node->ropR));
	node->opType = (tree_code) 0;
	node->toResolve = 0;
	node->next = NULL;
}

static void setVarName(var_t *type, tree var) {
	if (DECL_ARTIFICIAL(var)) {
		sprintf(type->val, "%d", var->decl_minimal.uid);
		type->varType = ARTIFICIAL;
	} else if (TREE_CODE(var) != INTEGER_CST) {
		sprintf(type->val, "%s", get_name(var));
		type->varType = VARIABLE;
	} else {
		sprintf(type->val, "%d",
				((TREE_INT_CST_HIGH(var) << HOST_BITS_PER_WIDE_INT)
						+ TREE_INT_CST_LOW(var)));
		type->varType = CONSTANT;
	}
}

static char *getOpType(tree_code opType) {
	char *buffer = (char *) xmalloc(100);
	switch (opType) {
	case PLUS_EXPR:
		return strcpy(buffer, "ADD");
		//break;

	case MINUS_EXPR:
		return strcpy(buffer, "SUBTRACT");
		//break;

	case MULT_EXPR:
		return strcpy(buffer, "MULTIPLY");
		//break;

	case TRUNC_DIV_EXPR:
	case CEIL_DIV_EXPR:
	case FLOOR_DIV_EXPR:
	case ROUND_DIV_EXPR:
		return strcpy(buffer, "DIVISION");
		//break;

	case NEGATE_EXPR:
		return strcpy(buffer, "NEGATE");

	case LSHIFT_EXPR:
		return strcpy(buffer, "LEFT_SHIFT");

	case RSHIFT_EXPR:
		return strcpy(buffer, "RIGHT_SHIFT");

	default:
		return NULL;
		//break;
	}
}

static char *initStr(char *string) {
	string[0] = '\0';
	return string;
}

static dNode *getNode(dNode *head, var_t var) {
	dNode *temp = head;
	while (temp != NULL) {
		if (!strcmp(temp->lop.val, var.val))
			return temp;
		temp = temp->next;
	}
}

/*static void test(dNode *head) {
	dNode *temp = head;
	while (temp != NULL) {
		fprintf(stderr, "\n%s %s", temp->lop.val, temp->temp);
		temp = temp->next;
	}
}*/

static void buildList(dNode *head) {
	dNode *curr = head;
	bool changes = true;
	dNode *ropL;
	dNode *ropR;
	while (changes) {
		changes = false;
		while (curr != NULL) {
			if (curr->lop.varType == ARTIFICIAL && !curr->resolved) {
				if (curr->ropL.varType != ARTIFICIAL
						&& curr->ropL.varType != ARTIFICIAL) {
					if (curr->ropR.varType == NULL_T) {
						sprintf(curr->temp, "%s", curr->ropL.val);
					} else {
						sprintf(curr->temp, "%s(%s,%s)",
								getOpType(curr->opType), curr->ropL.val,
								curr->ropR.val);
					}

					curr->resolved = true;
					changes = true;
				}

				else if (curr->ropL.varType == ARTIFICIAL
						|| curr->ropR.varType == ARTIFICIAL) {
					ropL = getNode(head, curr->ropL);
					ropR = getNode(head, curr->ropR);
					if (curr->ropL.varType == ARTIFICIAL && ropL->resolved) {
						sprintf(curr->temp, "%s(%s,", getOpType(curr->opType),
								ropL->temp);
						curr->toResolve--;
						changes = true;
					} else if (curr->ropL.varType != ARTIFICIAL) {
						sprintf(curr->temp, "%s(%s,", getOpType(curr->opType),
								curr->ropL.val);
					}

					if (curr->toResolve == 0) {
						strcat(curr->temp, curr->ropR.val);
						strcat(curr->temp, ")");
						curr->resolved = true;
					}
					if (curr->ropR.varType == ARTIFICIAL && ropR->resolved
							&& curr->toResolve == 1) {
						strcat(curr->temp, ropR->temp);
						strcat(curr->temp, ")");
						changes = true;
						curr->toResolve--;
						curr->resolved = true;
//						sprintf(curr->temp, "%s(%s,", getOpType(curr->opType),
//								getNode(curr->ropL)->temp);
					}
				}
			}

			curr = curr->next;
		}
	}

}

static char* lookup(dNode *head, var_t var) {
	dNode *curr = head;
	int changes = 1;
	if (var.varType == VARIABLE || var.varType == CONSTANT) {
		return xstrdup(var.val);
	}

	while (curr != NULL) {
		if (!strcmp(curr->lop.val, var.val)) {
			if (curr->lop.varType == ARTIFICIAL) {
				return xstrdup(curr->temp);
			}
		}

		curr = curr->next;
	}
}

static void display(dNode *head) {
	char *op;
	int blockPrinted = -1;
	for (dNode *curr = head; curr != NULL; curr = curr->next) {
		if (blockPrinted == -1 || blockPrinted != curr->bb_id) {
			fprintf(stderr, "\nbb%d:\n", curr->bb_id);
			fprintf(dump_file, "\nbb%d:\n", curr->bb_id);
			blockPrinted = curr->bb_id;
		}

		if (curr->lop.varType == VARIABLE) {
			fprintf(stderr, "(ASSIGN,");
			fprintf(stderr, curr->lop.val);
			fprintf(dump_file, "(ASSIGN,");
			fprintf(dump_file, curr->lop.val);

			//check for the RHS
			if (curr->ropR.varType == NULL_T) { //simple assign
				fprintf(stderr, ",%s)", lookup(head, curr->ropL));
				fprintf(dump_file, ",%s)", lookup(head, curr->ropL));
			} else if (curr->ropR.varType == UNARY_T) { //Negation for now
				op = getOpType(curr->opType);
				if (op != NULL) {
					fprintf(stderr, ",(%s(", op);
					fprintf(stderr, "%s))", lookup(head, curr->ropL));
					fprintf(dump_file, ",(%s(", op);
					fprintf(dump_file, "%s))", lookup(head, curr->ropL));
				}
			} else {
				op = getOpType(curr->opType);
				if (op != NULL) {
					fprintf(stderr, ",(%s(", op);
					fprintf(stderr, "%s", lookup(head, curr->ropL));
					fprintf(stderr, ",%s))", lookup(head, curr->ropR));
					fprintf(dump_file, ",(%s(", op);
					fprintf(dump_file, "%s", lookup(head, curr->ropL));
					fprintf(dump_file, ",%s))", lookup(head, curr->ropR));
				}
			}
			fprintf(stderr, "\n");
			fprintf(dump_file, "\n");
		}
	}
}

static void setResolveCount(dNode *node, tree operand) {
	if (DECL_ARTIFICIAL(operand)) {
		node->toResolve++;
	}
}

static void printLinkedList(dNode *head) {
	dNode *temp = head;
	while (temp) {
		fprintf(stderr, "operator: %s\n", getOpType(temp->opType));
		fprintf(stderr, "left: %s\n", temp->lop.val);
		fprintf(stderr, "right: %s\n", temp->ropL.val);
		fprintf(stderr, "\n");
		temp = temp->next;
	}
}

static unsigned int execute_pass_plugin(void) {
	basic_block bb;
	gimple_stmt_iterator gsi;
	gimple statement;
	tree lhsop;
	tree rhsop1;
	tree rhsop2;
	enum gimple_rhs_class rhsType;
	enum tree_code operatorType;
	tree *op1_p, *op2_p;
	dNode *head = NULL, *tail = NULL;

	FOR_EACH_BB(bb) {

		//fprintf(stderr, "BasicBlock - %d\n", bb->index);
		for (gsi = gsi_start_bb(bb); !gsi_end_p(gsi); gsi_next(&gsi)) {

			statement = gsi_stmt(gsi);
			lhsop = gimple_assign_lhs(statement);
			rhsop1 = gimple_assign_rhs1(statement);
			rhsop2 = gimple_assign_rhs2(statement);

			if (is_gimple_assign(statement)) {
				//debug_gimple_stmt(statement);
				rhsType = get_gimple_rhs_class(gimple_expr_code(statement));
				//populate list

				dNode *newNode = (dNode *) xmalloc(sizeof(dNode));
				init(newNode, bb->index);
				setVarName(&(newNode->lop), lhsop);

				//get the statement type
				if (rhsType == GIMPLE_SINGLE_RHS) {
					setVarName(&(newNode->ropL), rhsop1);
					setResolveCount(newNode, rhsop1);
					newNode->ropR.varType = NULL_T; //check for operator from this
				}

				//todo: use GIMPLE_UNARY_RHS for negate
				else if (rhsType == GIMPLE_UNARY_RHS) {
					setVarName(&(newNode->ropL), rhsop1);
					setResolveCount(newNode, rhsop1);
					newNode->ropR.varType = UNARY_T;
					newNode->opType = gimple_assign_rhs_code(statement);
				}

				else if (rhsType == GIMPLE_BINARY_RHS) {
					setVarName(&(newNode->ropL), rhsop1);
					setResolveCount(newNode, rhsop1);
					setVarName(&(newNode->ropR), rhsop2);
					setResolveCount(newNode, rhsop2);
					newNode->opType = gimple_assign_rhs_code(statement);
				}

				if (head == NULL)
					head = tail = newNode;
				else {
					tail->next = newNode;
					tail = tail->next;
				}

			} //close of assign if
		}
	}
	printLinkedList(head);
	buildList(head);
	display(head);
	return 0;
}

