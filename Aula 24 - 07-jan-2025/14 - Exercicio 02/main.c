#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tQueue * q_queue = queuealloc();

    push(q_queue, 2);
    push(q_queue, 6);
    push(q_queue, 7);
    push(q_queue, 8);
    push(q_queue, 20);
    pop(q_queue);
    queueprint(q_queue);

    q_queue = queuefree(q_queue);
    return 0;
}
