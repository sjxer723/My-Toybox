#include "sparse/linearize.h"
#include "sparse/symbol.h"
#include "sparse/expression.h"
#include "sparse/allocate.h"
#include "sparse/ptrlist.h"

#ifndef CALL_GRAPH_H
#define CALL_GRAPH_H

struct call_edge {
    struct call_node *caller;
    struct call_node *callee;
    int times;
};
DECLARE_PTR_LIST(call_edge_list, struct call_edge);

struct call_node {
    struct ident* id;
    struct call_edge_list* edges;
};

void generate_call_edges(struct entrypoint * ep);
void show_call_graph(struct symbol_list* syms);

static struct call_node* alloc_call_node(struct ident* id)
{   
    struct call_node* node = malloc(sizeof(struct call_node));
    node ->id = id;
    return node;
}

#endif