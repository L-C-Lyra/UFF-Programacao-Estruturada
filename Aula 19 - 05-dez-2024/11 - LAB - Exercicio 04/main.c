#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list_1 = NULL;

    l_list_1 = listalloc(l_list_1, 25);
    l_list_1 = listalloc(l_list_1, 15);
    l_list_1 = listalloc(l_list_1, 10);
    l_list_1 = listalloc(l_list_1, 8);
    l_list_1 = listalloc(l_list_1, 2);

    listprint(l_list_1);
    printf("\n");

    tList * l_list_2 = NULL;

    l_list_2 = listalloc(l_list_2, 14);
    l_list_2 = listalloc(l_list_2, 12);
    l_list_2 = listalloc(l_list_2, 7);

    listprint(l_list_2);
    printf("\n");

    tList * l_list_3 = listmerge(l_list_1, l_list_2);

    listprint(l_list_3);

    l_list_3 = listfree(l_list_3);
    return 0;
}
