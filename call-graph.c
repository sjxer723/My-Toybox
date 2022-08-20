#include <stdio.h>
#include "call-graph.h"
#include "sparse/symbol.h"
#include "sparse/linearize.h"
#include "sparse/expression.h"

void generate_call_edges(struct entrypoint * ep)
{
    struct basic_block* bb_iter = NULL;
    struct call_node * node = NULL;
    
    
    node = alloc_call_node(ep->name->ident);
    printf("caller: %s\n", show_ident(node->id));
    FOR_EACH_PTR(ep->bbs, bb_iter){
        struct instruction *insn_iter = NULL;

        FOR_EACH_PTR(bb_iter->insns, insn_iter){
            switch (insn_iter->opcode)
            {
            case OP_CALL:
                printf("callee: %s\n", show_ident(insn_iter->func->ident));
                break;
            default:
                break;
            }
        }END_FOR_EACH_PTR(insn_iter);
    }END_FOR_EACH_PTR(bb_iter);
}