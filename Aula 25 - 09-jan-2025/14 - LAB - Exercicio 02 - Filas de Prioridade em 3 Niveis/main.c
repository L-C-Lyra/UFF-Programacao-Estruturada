#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tQueue * q_queue_a = queuealloc();
    tQueue * q_queue_b = queuealloc();
    tQueue * q_queue_c = queuealloc();

    push_queues(q_queue_a, q_queue_b, q_queue_c, 43, 2);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 100, 3);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 2, 1);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 6, 1);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 200, 3);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 7, 1);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 65, 2);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 300, 3);
    push_queues(q_queue_a, q_queue_b, q_queue_c, 54, 2);
    queuesprint(q_queue_a, q_queue_b, q_queue_c);

    while(!empty_queues(q_queue_a, q_queue_b, q_queue_c)){
        printf("\nSai = %d", pop_queues(q_queue_a, q_queue_b, q_queue_c));
    }

    q_queue_a = queuefree(q_queue_a);
    q_queue_b = queuefree(q_queue_b);
    q_queue_c = queuefree(q_queue_c);
    return 0;
}
