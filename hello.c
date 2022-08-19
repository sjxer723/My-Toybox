#include <stdio.h>
#include "sparse/lib.h"
#include "sparse/linearize.h"

int main(int argc, char **argv)
{

	struct string_list *filelist = NULL;
	sparse_initialize(argc, argv, &filelist);
    
    printf("hello world\n");
	return 0;
}
