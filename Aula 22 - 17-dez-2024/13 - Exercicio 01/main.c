#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tStacks s_stacks;
    stacksalloc(&s_stacks, 6);

    pushes(&s_stacks, 1, 54);
    pushes(&s_stacks, 1, 76);

    pushes(&s_stacks, 2, 1);
    pushes(&s_stacks, 2, 2);
    pushes(&s_stacks, 2, 3);
    pushes(&s_stacks, 2, 4);

    pushes(&s_stacks, 1, 130);

    return 0;
}
