/*
 * A unit test and example of how to use the simple C hashmap
 */
#include <stdio.h>
#include "sparse/lib.h"
#include "sparse/linearize.h"
#include "sparse/symbol.h"
#include "sparse/expression.h"
#include "call-graph.h"
#include "utils/hashmap.h"
#include <assert.h>

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)


int main(int argc, char **argv)
{
	struct string_list *filelist = NULL;
	char *file = NULL;
    struct symbol_list *syms = NULL;
    struct symbol *sym = NULL;
    struct entrypoint *ep = NULL;
	map_t map = NULL;

	map = hashmap_new();
	sparse_initialize(argc, argv, &filelist);
    FOR_EACH_PTR(filelist, file){
        syms = sparse(file);

	    FOR_EACH_PTR(syms, sym) {
	    	expand_symbol(sym);
	    	ep = linearize_symbol(sym);
	    	if (ep)
	    		show_entry(ep);
            generate_call_edges(ep);
	    } END_FOR_EACH_PTR(sym);
    }END_FOR_EACH_PTR(file);

	return 0;
}