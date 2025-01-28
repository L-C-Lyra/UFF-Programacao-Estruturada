#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    int largest_n;
    tList * l_list = NULL;

    l_list = pos_circ_listalloc(l_list, 4, 0);
    l_list = pos_circ_listalloc(l_list, 12, 1);
    l_list = pos_circ_listalloc(l_list, 18, 2);
    l_list = pos_circ_listalloc(l_list, 20, 3);

    circ_listprint(l_list);

    largest_n = circ_list_largest_elem(l_list);
    if(largest_n != -1){
        printf("Maior Elemento: %4d", largest_n);
    }

    l_list = circ_listfree(l_list);
    return 0;
}
