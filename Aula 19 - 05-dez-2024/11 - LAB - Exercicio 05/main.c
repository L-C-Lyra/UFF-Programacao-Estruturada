#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list = NULL;

    l_list = listalloc(l_list, 5);
    l_list = listalloc(l_list, 4);
    l_list = listalloc(l_list, 3);
    l_list = listalloc(l_list, 2);
    l_list = listalloc(l_list, 1);

    listprint(l_list);
    printf("\n");

    l_list = rotate_right(l_list, 1);
    listprint(l_list);
    printf("\n");

    l_list = rotate_right(l_list, 3);
    listprint(l_list);
    printf("\n");

    l_list = rotate_right(l_list, 5);
    listprint(l_list);
    printf("\n");

    l_list = rotate_right(l_list, 6);

    l_list = listfree(l_list);
    return 0;
}
