/*-----------------------------------------------------------------------------
 *  "gcc-plugin.h" must be the FIRST file to be included 
 *-----------------------------------------------------------------------------*/
#include "gcc-plugin.h"
#include "config.h"
#include <stdio.h>
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "input.h"
#include "tm_p.h"
#include "diagnostic.h"
#include "tree-flow.h"
#include "tree-pass.h"
#include "toplev.h"
#include "gimple-pretty-print.h"
#include "cgraph.h"
#include "tree.h"
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

/*function declarations*/
static unsigned int inter_gimple_manipulation(void);

/*-----------------------------------------------------------------------------
 *  Structure of the pass we want to insert, identical to a regular ipa pass
 *-----------------------------------------------------------------------------*/
struct gimple_opt_pass pass_plugin = { { SIMPLE_IPA_PASS,
		"inter_gimple_manipulation", /*  name */
		NULL, /*  gate */
		inter_gimple_manipulation, /*  execute */
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
 opt_pass' field of 'gimple_opt_pass'
 defined above */
"pta", /* Name of the reference pass for hooking up
 the new pass. */
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

typedef enum {
	WHITE, GRAY, BLACK
} COLOR;

typedef struct sNode {
	char name[100];
	int id;
	int dependencyCount;
	int dependency[20];
	int size;
	bool done;
	COLOR visited;
	bool isRec;
	struct sNode *next;
} dNode;

dNode *head = NULL;

void display() {
	dNode *curr = head;
	int i;
	while (curr) {
		fprintf(stderr, "\n%s:", curr->name);
		fprintf(stderr, "%d %d %d**", curr->id, curr->dependencyCount,
				curr->size);
		for (i = 0; i < curr->dependencyCount; i++) {
			fprintf(stderr, "%d,", curr->dependency[i]);
		}

		curr = curr->next;
	}
}

dNode* getNode(char *name) {
	dNode *curr = head;
	while (curr) {
		if (strcmp(curr->name, name) == 0) {
			return curr;
		}

		curr = curr->next;
	}

	return NULL;
}

int getId(char *name) {
	dNode *curr = head;
	while (curr) {
		if (strcmp(curr->name, name) == 0) {
			return curr->id;
		}

		curr = curr->next;
	}

	return 0;
}

dNode *getNodeFromId(int id) {
	dNode *curr = head;
	while (curr) {
		if (curr->id == id) {
			return curr;
		}
		curr = curr->next;
	}

	return NULL;
}

int getSize(char *name) {
	struct cgraph_node *node;
	basic_block bb;
	gimple statement;
	enum gimple_code code;
	gimple_stmt_iterator gsi;

	int size = 0;
	for (node = cgraph_nodes; node; node = node->next) {
		/* Nodes without a body, and clone nodes are not interesting. */
		if (!gimple_has_body_p(node->decl) || node->clone_of)
			continue;

		if (strcmp(cgraph_node_name(node), name) == 0) {
			set_cfun(DECL_STRUCT_FUNCTION(node->decl));
			//fprintf(stderr, "%s  -->  ", cgraph_node_name(node));
			FOR_ALL_BB(bb) {
				for (gsi = gsi_start_bb(bb); !gsi_end_p(gsi); gsi_next(&gsi)) {
					statement = gsi_stmt(gsi);
					code = gimple_code(statement);
					//debug_gimple_stmt(statement);
					if (code != GIMPLE_CALL) {
						size++;
					}
				}
			}

			return size;
		}
	}

	return 0;
}
void bubbleSort(int *array, int n) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n - 1; y++) {
			if (array[y] > array[y + 1]) {
				int temp = array[y + 1];
				array[y + 1] = array[y];
				array[y] = temp;
			}
		}
	}
}

void fixDependencies(int id, int size) {
	dNode* curr = head;
	int i, count = 0;
	while (curr) {
		count = 0;
		for (i = 0; i < curr->dependencyCount; i++) {
			if (curr->dependency[i] == id) {
				curr->size = curr->size + size;
				curr->dependency[i] = 999;
				count++;
			}
		}

		bubbleSort(curr->dependency, curr->dependencyCount);
		curr->dependencyCount = curr->dependencyCount - count;

		curr = curr->next;
	}
}

bool isVisited(int id) {
	return getNodeFromId(id)->visited == BLACK ? true : false;
}

void reInitialize() {
	dNode *curr = head;
	for (; curr; curr = curr->next) {
		curr->visited = WHITE;
		curr->isRec = false;
	}
}

void dfs(dNode *src, dNode *start) {
	start->visited = BLACK;
	//fprintf(stderr, "visited %s %s\n", src->name, start->name);
	for (int i = 0; i < start->dependencyCount; i++) {
		if (!isVisited(start->dependency[i])) {
			dfs(src, getNodeFromId(start->dependency[i]));
		} else if (src->visited == BLACK) {
			if (src->id == start->dependency[i]) {
				src->isRec = true;
				return;
			}
		}
	}
}

/* Driver Routine. */
static unsigned int inter_gimple_manipulation(void) {
	if (in_lto_p == 1) {
		struct cgraph_node *node;
		struct cgraph_edge *e;
		dNode *newNode;
		dNode *temp, *curr;
		int id = 1;
		bool changes = true;
		int max = -1;
		bool isRecursionDetected = false;

		/* Iterating over the cgraph nodes */
		for (node = cgraph_nodes; node; node = node->next) {
			/* Nodes without a body, and clone nodes are not interesting. */
			if (!gimple_has_body_p(node->decl) || node->clone_of)
				continue;

			newNode = (dNode*) xmalloc(sizeof(dNode));
			newNode->dependencyCount = 0;
			newNode->size = 0;
			newNode->id = id++;
			strcpy(newNode->name, cgraph_node_name(node));
			newNode->next = NULL;
			newNode->done = false;

			if (head == NULL) {
				head = newNode;
			} else {
				newNode->next = head;
				head = newNode;
			}
		}

		//display();

		for (node = cgraph_nodes; node != NULL; node = node->next) {
			/* Nodes without a body, and clone nodes are not interesting. */
			if (!gimple_has_body_p(node->decl) || node->clone_of)
				continue;

			temp = getNode(xstrdup(cgraph_node_name(node)));

			for (e = node->callees; e != NULL && !isRecursionDetected;
					e = e->next_callee) {
				if (getNode(xstrdup(cgraph_node_name(e->callee))) != NULL) {

					//check internal recursion
					if (!strcmp(cgraph_node_name(e->callee), temp->name)) {
						fprintf(stderr,
								"Internal Recursion detected... Rejecting!\n");
						fprintf(dump_file,
								"Internal Recursion detected... Rejecting!\n");
						isRecursionDetected = true;
						break;
					}

					temp->dependency[temp->dependencyCount] = getId(
							xstrdup(cgraph_node_name(e->callee)));
					temp->dependencyCount++;
				} else {
					temp->size++;
				}
			}
		}

		//display();

		if (!isRecursionDetected) {
			for (curr = head; curr && !isRecursionDetected; curr = curr->next) {
				reInitialize();
				dfs(curr, curr);

				if (curr->isRec == true) {
					isRecursionDetected = true;
				}
			}

			if (isRecursionDetected) {
				fprintf(stderr, "External Recursion Detected... Rejecting!\n");
				fprintf(dump_file,
						"External Recursion Detected... Rejecting!\n");
			}
		}

		if (!isRecursionDetected) {
			while (changes) {
				changes = false;
				curr = head;
				while (curr) {
					if (!curr->done && curr->dependencyCount == 0) {
						curr->size = curr->size + getSize(curr->name);
						curr->done = true;
						fixDependencies(curr->id, curr->size);
						changes = true;
					}

					curr = curr->next;
				}
			}

			//display();

			int total = 0;
			for (curr = head; curr; curr = curr->next) {
				if (strstr(curr->name, "main")) {
					total = curr->size;
				}
				fprintf(stderr, "[FUNCTION:] %s, [SIZE:] %d\n", curr->name,
						curr->size);
				fprintf(dump_file, "[FUNCTION:] %s, [SIZE:] %d\n", curr->name,
						curr->size);
			}

			fprintf(stderr, "\nTotal statements: %d\n", total);
			fprintf(dump_file, "\nTotal statements: %d\n", total);
		}
	}
	return 0;

}
