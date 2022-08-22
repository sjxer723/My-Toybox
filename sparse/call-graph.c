#include "call-graph.h"
#include "expression.h"
#include "linearize.h"
#include "symbol.h"
#include <stdio.h>

struct call_node *main_node;
struct ident *main_id;
int reachable_nodes_num = 0;

int generate_call_edges(struct entrypoint *ep, struct call_node *node,
                        map_t map) {
  	struct basic_block *bb_iter = NULL;

 	FOR_EACH_PTR(ep->bbs, bb_iter) {
    	struct instruction *insn_iter = NULL;

    	FOR_EACH_PTR(bb_iter->insns, insn_iter) {
    		switch (insn_iter->opcode) {
    		case OP_CALL:
        		char *key = malloc(sizeof(char) * 100);
        		const char *name = show_ident(insn_iter->func->ident);
        		int err = MAP_OK;
        		struct call_node *child = NULL;

        		if (!key) {
        			printf("Error: no avaiable memory space\n");
        			return 0;
        		}
        		snprintf(key, sizeof(name), name);
        		err = hashmap_get(map, key, (any_t *)&child);
        		if (err != MAP_OK) {
        			child = alloc_call_node(insn_iter->func->ident);
        			hashmap_put(map, key, child);
        		}
        		add_call_node(&node->neighbors, child);
        		printf("Call Edge: caller: %s --> callee: %s\n", show_ident(node->id),
        		    	show_ident(insn_iter->func->ident));
        		break;
      		default:
        		break;
      		}
    	}
    	END_FOR_EACH_PTR(insn_iter);
  	}
  	END_FOR_EACH_PTR(bb_iter);

	return 1;
}

void call_graph_dfs(map_t map, struct call_node *node) {
	struct call_node *child_iter = 0;

	if (!node || node->visited)
		return;
	reachable_nodes_num++;
	node->visited = 1;
	FOR_EACH_PTR(node->neighbors, child_iter) { call_graph_dfs(map, child_iter); }
	END_FOR_EACH_PTR(child_iter);
}

int get_reachable_nodes_num(map_t map) {
  	call_graph_dfs(map, main_node);
  	return reachable_nodes_num;
}