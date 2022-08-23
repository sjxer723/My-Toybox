#include "linearize.h"
#include "symbol.h"
#include "expression.h"
#include "allocate.h"
#include "ptrlist.h"
#include "hashmap.h"

#ifndef CALL_GRAPH_H
#define CALL_GRAPH_H


struct call_node {
    struct ident* id;
    struct call_node_list* neighbors;
    int visited;
};

DECLARE_PTR_LIST(call_node_list, struct call_node);

int generate_call_edges(struct entrypoint * ep, struct call_node *node, map_t map);
void show_call_graph(struct symbol_list* syms);
int get_reachable_nodes_num(map_t map);

static struct call_node* alloc_call_node(struct ident* id)
{   
    struct call_node* node = __alloc_call_node(0);
    node ->id = id;
    node ->visited = 0;
    return node;
}

static inline void add_call_node(struct call_node_list **list, struct call_node *node)
{
	add_ptr_list(list, node);
}

#endif