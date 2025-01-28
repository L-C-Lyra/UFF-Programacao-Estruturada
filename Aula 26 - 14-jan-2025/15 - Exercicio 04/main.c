#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    int n_1 = 3;
    tStack s_stack_1;
    stackalloc(&s_stack_1, n_1);
    int n_2 = 3;
    tStack s_stack_2;
    stackalloc(&s_stack_2, n_2);

    push(&s_stack_1, 7);
    push(&s_stack_1, 13);
    push(&s_stack_1, 76);

    push(&s_stack_2, 76);
    push(&s_stack_2, 7);
    push(&s_stack_2, 13);

    if(pilhasIguais(&s_stack_1, n_1, &s_stack_2, n_2)){
        printf("As Pilhas SAO IGUAIS.");
    }else{
        printf("As Pilhas NAO SAO IGUAIS.");
    }

    return 0;
}
