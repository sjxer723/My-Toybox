#include <stdio.h>
#include "call-graph.h"
#include "symbol.h"
#include "linearize.h"
#include "expression.h"

struct call_node *main_node;
struct ident *main_id;

int generate_call_edges(struct entrypoint *ep, struct call_node *node, map_t map)
{
    struct basic_block* bb_iter = NULL;
    
    FOR_EACH_PTR(ep->bbs, bb_iter){
        struct instruction *insn_iter = NULL;

        FOR_EACH_PTR(bb_iter->insns, insn_iter){
            switch (insn_iter->opcode)
            {
            case OP_CALL:
                char *key = malloc(sizeof(char)*100);
                const char * name = show_ident(insn_iter->func->ident);
                int err = MAP_OK;
                struct call_node* neighbor_node = NULL;

                if(!key) {
                    printf("Error: no avaiable memory space\n");
                    return 0;
                }
                snprintf(key, sizeof(name), name);
                err = hashmap_get(map, key, (any_t *)&neighbor_node);
                if(err != MAP_OK){
                    neighbor_node = alloc_call_node(insn_iter->func->ident);
                    hashmap_put(map, key, neighbor_node);
                }
                add_call_node(&node->neighbors, neighbor_node);
                printf("Call Edge: caller: %s --> callee: %s\n", show_ident(node->id), show_ident(insn_iter->func->ident));
                break;
            default:
                break;
            }
        }END_FOR_EACH_PTR(insn_iter);
    }END_FOR_EACH_PTR(bb_iter);

    return 1;
}