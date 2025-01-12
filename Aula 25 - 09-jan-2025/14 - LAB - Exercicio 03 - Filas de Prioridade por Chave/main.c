#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tQueue * q_queue = queuealloc();

    push_queue(q_queue, 42);
    push_queue(q_queue, 100);
    push_queue(q_queue, 2);
    push_queue(q_queue, 6);
    push_queue(q_queue, 200);
    queueprint(q_queue);

    while(!empty_queue(q_queue)){
        printf("\nSai = %d\n", prio_pop_queue(q_queue));
        queueprint(q_queue);
    }

    printf("Sai = %d", prio_pop_queue(q_queue));
    queueprint(q_queue);

    q_queue = queuefree(q_queue);
    return 0;
}
