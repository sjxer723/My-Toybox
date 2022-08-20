/*
 * A unit test and example of how to use the simple C hashmap
 */
#include <stdio.h>
#include "sparse/lib.h"
#include "sparse/linearize.h"
#include "sparse/symbol.h"
#include "sparse/expression.h"
#include "sparse/call-graph.h"
#include "utils/hashmap.h"
#include <assert.h>
#include "string.h"

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
	    	expand_symbol(sym);
	    	ep = linearize_symbol(sym);
			if (ep)
	    	{
				char* key = malloc(sizeof(char) *100);
				const char* name = show_ident(ep->name->ident);

				snprintf(key, sizeof(name), name);
				error = hashmap_get(map, key, (any_t *)&node);
				printf("error = %d\n", error);
				if(error == MAP_MISSING){
					node = alloc_call_node(ep->name->ident);
					hashmap_put(map, key, (any_t)node);
				}
	    		show_entry(ep);
				generate_call_edges(ep, node, map);
			}
	    } END_FOR_EACH_PTR(sym);
    }END_FOR_EACH_PTR(file);

	return 0;
}