#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tStack s_stack;
    stackalloc(&s_stack, 10);

    push(&s_stack, 7);
    push(&s_stack, 13);
    push(&s_stack, 76);
    stackprint(&s_stack);

    push_bottom(&s_stack, 100);
    stackprint(&s_stack);

    stackreverse(&s_stack);
    stackprint(&s_stack);

    return 0;
}
