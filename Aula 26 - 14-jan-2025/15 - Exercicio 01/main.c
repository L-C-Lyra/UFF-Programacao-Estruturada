#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tList * l_list = NULL;

    l_list = listalloc(l_list, 1);
    listprint(l_list);

    l_list = listalloc(l_list, 3);
    listprint(l_list);

    l_list = listalloc(l_list, 2);
    listprint(l_list);

    l_list = listalloc(l_list, 5);
    listprint(l_list);

    l_list = listalloc(l_list, 4);
    listprint(l_list);

    l_list = listfree(l_list);
    return 0;
}
