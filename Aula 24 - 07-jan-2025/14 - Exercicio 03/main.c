#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tQueue q_queue;
    queuealloc(&q_queue, 7);

    push_backward(&q_queue, 54);
    push_backward(&q_queue, 23);
    printf("%d\n", pop_forward(&q_queue));
    push_forward(&q_queue, 100);
    printf("%d\n", pop_backward(&q_queue));

    return 0;
}
