#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list = NULL;

    l_list = listalloc(l_list, 34);
    l_list = listalloc(l_list, 3);
    l_list = listalloc(l_list, 15);
    l_list = listalloc(l_list, 25);
    l_list = listalloc(l_list, 65);
    l_list = listalloc(l_list, 7);
    l_list = listalloc(l_list, 98);

    listprint(l_list);
    printf("\n");

    pos_listprint(l_list, 3);
    printf("\n");
    pos_listprint(l_list, 1);
    printf("\n");
    pos_listprint(l_list, 7);
    printf("\n");
    pos_listprint(l_list, 9);

    l_list = listfree(l_list);
    return 0;
}
