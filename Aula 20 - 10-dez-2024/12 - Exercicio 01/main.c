#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list_1 = NULL;

    l_list_1 = pos_circ_listalloc(l_list_1, 4, 0);
    l_list_1 = pos_circ_listalloc(l_list_1, 12, 1);
    l_list_1 = pos_circ_listalloc(l_list_1, 18, 2);
    l_list_1 = pos_circ_listalloc(l_list_1, 20, 3);

    circ_listprint(l_list_1);
    printf("\n");

    tList * l_list_2 = NULL;

    l_list_2 = pos_circ_listalloc(l_list_2, 4, 0);
    l_list_2 = pos_circ_listalloc(l_list_2, 12, 1);

    circ_listprint(l_list_2);
    printf("\n");

    tList * l_list_3 = circ_listconcatenate(l_list_1, l_list_2);

    circ_listprint(l_list_3);

    l_list_3 = circ_listfree(l_list_3);
    return 0;
}
