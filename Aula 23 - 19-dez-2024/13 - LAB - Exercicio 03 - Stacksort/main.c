#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tStack s_stack;
    stackalloc(&s_stack, 10);

    push(&s_stack, 8);
    push(&s_stack, 5);
    push(&s_stack, 77);
    push(&s_stack, 1);
    push(&s_stack, 2);
    stackprint(&s_stack);

    stacksort(&s_stack);
    stackprint(&s_stack);

    return 0;
}
