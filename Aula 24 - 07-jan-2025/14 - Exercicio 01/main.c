#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tQueue q_queue;
    queuealloc(&q_queue, 6);

    push(&q_queue, 56);
    push(&q_queue, 15);
    push(&q_queue, 4);
    push(&q_queue, 84);
    push(&q_queue, 25);
    queueprint(&q_queue);

    return 0;
}
