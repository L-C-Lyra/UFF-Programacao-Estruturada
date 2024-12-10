#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list = NULL;

    l_list = listalloc(l_list, 12);
    l_list = listalloc(l_list, 67);
    l_list = listalloc(l_list, 7);
    l_list = listalloc(l_list, 78);
    l_list = listalloc(l_list, 31);

    listprint(l_list);
    printf("\n");

    if(list_is_sorted(l_list)){
        printf("A Lista ESTA Ordenada.");
    }else{
        printf("A Lista NAO ESTA Ordenada.");
    }

    l_list = listfree(l_list);
    return 0;
}
