#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tStack s_stack;
    stackalloc(&s_stack, 10);

    push(&s_stack, 7);
    push(&s_stack, 13);
    push(&s_stack, 7);
    push(&s_stack, 79);
    stackprint(&s_stack);

    stackremove(&s_stack, 7);
    stackprint(&s_stack);

    return 0;
}
