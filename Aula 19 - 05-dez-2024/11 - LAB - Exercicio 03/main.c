#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list = NULL;

    l_list = listalloc(l_list, 33);
    l_list = listalloc(l_list, 33);
    l_list = listalloc(l_list, 33);
    l_list = listalloc(l_list, 33);
    l_list = listalloc(l_list, 28);
    l_list = listalloc(l_list, 28);
    l_list = listalloc(l_list, 18);
    l_list = listalloc(l_list, 2);
    l_list = listalloc(l_list, 2);
    l_list = listalloc(l_list, 2);

    listprint(l_list);
    printf("\n");

    l_list = duplicate_noderemove(l_list);

    listprint(l_list);

    l_list = listfree(l_list);
    return 0;
}
