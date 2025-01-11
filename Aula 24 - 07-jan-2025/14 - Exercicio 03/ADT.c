typedef struct typeQueue{
    int size;
    int start;
    int end;
    int * vet;
}tQueue;

void queuealloc(tQueue * q_queue, int size){
    q_queue -> size = size;
    q_queue -> start = -1;
    q_queue -> end = -1;
    q_queue -> vet = (int *) malloc((q_queue -> size) * sizeof(int));
}

int empty_queue(tQueue * q_queue){
    if(q_queue -> start == q_queue -> end){
        return 1;
    }
    return 0;
}

int full_queue(tQueue * q_queue){
    if(q_queue -> end == (q_queue -> size - 1)){
        return 1;
    }
    return 0;
}

void push_forward(tQueue * q_queue, int elem){
    if(q_queue -> start == -1){
        printf("Fila Cheia pela Frente.\n");
    }else{
        q_queue -> vet[q_queue -> start] = elem;
        q_queue -> start--;
    }
}

int pop_forward(tQueue * q_queue){
    int elem = -1;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        q_queue -> start++;
        elem = q_queue -> vet[q_queue -> start];
    }

    return elem;
}

void push_backward(tQueue * q_queue, int elem){
    if(full_queue(q_queue)){
        printf("Fila Cheia por Tras.\n");
    }else{
        q_queue -> end++;
        q_queue -> vet[q_queue -> end] = elem;
    }
}

int pop_backward(tQueue * q_queue){
    int elem = -1;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        elem = q_queue -> vet[q_queue -> end];
        q_queue -> end--;
    }

    return elem;
}
