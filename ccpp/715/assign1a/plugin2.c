

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
struct gimple_opt_pass pass_plugin = { { GIMPLE_PASS, "dominator", /*  name */
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

// Structure used for storing the dominator info.
typedef struct sNode {
	int key;
	int doms[100];
	int numValues;
	struct sNode *next;
} dNode;

dNode *domHead = NULL;

// Returns the dominator info corresponding to the passed in block id.
dNode* getDominatorInfo(int key) {
	dNode *curr = domHead;
	while (curr) {
		if (curr->key == key) {
			return curr;
		} else {
			curr = curr->next;
		}
	}

	return NULL;
}

// Performs the intersection between the dominators of the passed in nodes.
void intersection(dNode *a, dNode *b) {
	int i, j, temp[100], k = 0, flag = 0;
	if (b->numValues < 0) {
		//set b to a
		b->numValues = a->numValues;
		for (i = 0; i < a->numValues; i++) {
			b->doms[i] = a->doms[i];
		}
	} else {
		for (i = 0; i < a->numValues; i++) {
			flag = 0;
			for (j = 0; j < b->numValues; j++) {
				if (a->doms[i] == b->doms[j]) {
					flag = 1;
					break;
				}
			}

			if (flag == 1) {
				temp[k] = a->doms[i];
				k++;
			}
		}

		for (i = 0; i < k; i++) {
			a->doms[0] = temp[i];
		}

		a->numValues = k;
	}
}

/* function to insert a new_node in a list. Note that this
 function expects a pointer to head_ref as this can modify the
 head of the input linked list (similar to push())*/
void sortedInsert(dNode *head_ref, dNode *new_node) {
	dNode *current;
	/* Special case for the head end */
	if (head_ref == NULL || head_ref->key >= new_node->key) {
		new_node->next = head_ref;
		head_ref = new_node;
	} else {
		/* Locate the node before the point of insertion */
		current = head_ref;
		while (current->next != NULL && current->next->key < new_node->key) {
			current = current->next;
		}

		new_node->next = current->next;
		current->next = new_node;
	}
}

static unsigned int execute_pass_plugin(void) {
	int i, j, n = 0;
	edge e;
	edge_iterator ei;
	basic_block bb, bb1, b;
	dNode *newNode;

	// Adding the dominator info of entry block.
	// The only dominator of entry block is the entry block itself.
	newNode = (dNode*) xmalloc(sizeof(dNode));
	newNode->key = ENTRY_BLOCK_PTR->index;
	newNode->doms[0] = ENTRY_BLOCK_PTR->index;
	newNode->numValues = 1;
	newNode->next = NULL;
	domHead = newNode;

	// Calculating the dominators of all the nodes except the entry and exit blocks.
        //printf("%d",sizeof(BASIC_BLOCK));
	FOR_EACH_BB_FN (bb, cfun) {
		n = 0;

		newNode = (dNode*) xmalloc(sizeof(dNode));
		newNode->key = bb->index;

                //for(int i=0;i<)

		// Adding the entry block to the list of dominators.
		newNode->doms[n++] = 0;

		FOR_EACH_BB_FN (bb1, cfun) {
			if (dominated_by_p(CDI_DOMINATORS, bb, bb1)) {
				newNode->doms[n++] = bb1->index;
			}
		}

		newNode->numValues = n;

		sortedInsert(domHead, newNode);
	}

	// Finding the dominators of the exit block.
	dNode *result = (dNode *) xmalloc(sizeof(dNode));
	result->key = EXIT_BLOCK_PTR->index;
	result->numValues = -1;

	FOR_EACH_EDGE (e, ei, EXIT_BLOCK_PTR->preds) {
		basic_block pred_bb = e->src;
		int arr[100];

		dNode *info = getDominatorInfo(pred_bb->index);
		intersection(info, result);
	}

	// Adding the exit block to its own list of dominators.
	result->doms[result->numValues++] = EXIT_BLOCK_PTR->index;
	sortedInsert(domHead, result);

	// Printing the dominators of the blocks.
	dNode *currDom = domHead;
	while (currDom) {
		printf("Dom(%d): {", currDom->key);
		fprintf(dump_file,"Dom(%d): {", currDom->key);

		for (i = 0; i < currDom->numValues - 1; i++) {
			printf("%d,", currDom->doms[i]);
			fprintf(dump_file,"%d,", currDom->doms[i]);
		}

		printf("%d}", currDom->doms[currDom->numValues - 1]);
		printf("\n");

		fprintf(dump_file,"%d}", currDom->doms[currDom->numValues - 1]);
		fprintf(dump_file,"\n");

		currDom = currDom->next;
	}

	return 0;
}
