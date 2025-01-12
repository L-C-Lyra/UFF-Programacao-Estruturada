#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    int n = 10;
    tStack s_stack_a, s_stack_b;
    stackalloc(&s_stack_a, n);
    stackalloc(&s_stack_b, n);

    push_stack_queue(&s_stack_a, &s_stack_b, 42);
    push_stack_queue(&s_stack_a, &s_stack_b, 54);
    push_stack_queue(&s_stack_a, &s_stack_b, 65);
    push_stack_queue(&s_stack_a, &s_stack_b, 76);

    printf("Sai = %d\n", pop_stack_queue(&s_stack_a, &s_stack_b));
    printf("Sai = %d\n", pop_stack_queue(&s_stack_a, &s_stack_b));

    push_stack_queue(&s_stack_a, &s_stack_b, 100);
    push_stack_queue(&s_stack_a, &s_stack_b, 200);

    printf("Sai = %d\n", pop_stack_queue(&s_stack_a, &s_stack_b));
    printf("Sai = %d\n", pop_stack_queue(&s_stack_a, &s_stack_b));
    printf("Sai = %d\n", pop_stack_queue(&s_stack_a, &s_stack_b));
    printf("Sai = %d\n", pop_stack_queue(&s_stack_a, &s_stack_b));
    printf("Sai = %d", pop_stack_queue(&s_stack_a, &s_stack_b));

    return 0;
}
