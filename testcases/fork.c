#include <unistd.h>  
#include <stdio.h> 

int  main()
{
    for(int i=0;i<5;i++){
        fork();
    }
    return 0;
}