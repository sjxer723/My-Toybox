/*
 * A unit test and example of how to use the simple C hashmap
 */
#include <stdio.h>
#include <assert.h>
#include "string.h"
#include "lib.h"
#include "linearize.h"
#include "symbol.h"
#include "expression.h"
#include "call-graph.h"
#include "hashmap.h"

extern struct call_node *main_node;
extern struct ident *main_id;

static void show_call_graph_data(map_t map)
{
	fprintf(stdout, "Number of nodes in Call graph:                %d\n", hashmap_length(map));
	fprintf(stdout, "Number of reachable nodes in Call graph:      %d\n", get_reachable_nodes_num(map));
}

int main(int argc, char **argv)
{
	struct string_list *filelist = NULL;
	char *file = NULL;
    struct symbol_list *syms = NULL;
    struct symbol *sym = NULL;
    struct entrypoint *ep = NULL;
	map_t map = NULL;
	int error = MAP_OK;
	struct call_node *node = NULL;
				
	map = hashmap_new();
	sparse_initialize(argc, argv, &filelist);
		
	FOR_EACH_PTR(filelist, file){
        syms = sparse(file);
	    FOR_EACH_PTR(syms, sym) {
			if(!sym) continue;

	    	expand_symbol(sym);
	    	ep = linearize_symbol(sym);
			if (ep)
	    	{
				char* key = malloc(sizeof(char) *100);
				const char* name = show_ident(ep->name->ident);

				snprintf(key, sizeof(name), name);
				error = hashmap_get(map, key, (any_t *)&node);
				if(error != MAP_OK){
					node = alloc_call_node(ep->name->ident);
					hashmap_put(map, key, (any_t)node);
				}

				if(!strcmp("main", show_ident(sym->ident))){
					main_id = sym->ident;
					main_node = node;
				}
	    		//show_entry(ep);
				generate_call_edges(ep, node, map);
			}
	    } END_FOR_EACH_PTR(sym);
    }END_FOR_EACH_PTR(file);
 	show_call_graph_data(map);

	return 0;
}