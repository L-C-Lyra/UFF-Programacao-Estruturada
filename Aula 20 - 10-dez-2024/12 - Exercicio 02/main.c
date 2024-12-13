#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list = NULL;

    l_list = pos_listalloc(l_list, 4, 0);
    l_list = pos_listalloc(l_list, 12, 1);
    l_list = pos_listalloc(l_list, 18, 2);
    l_list = pos_listalloc(l_list, 20, 3);

    listprint(l_list);
    printf("\n");

    l_list = listinvert(l_list);

    listprint(l_list);

    l_list = listfree(l_list);
    return 0;
}
