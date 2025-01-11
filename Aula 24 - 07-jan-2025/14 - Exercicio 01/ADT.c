typedef struct typeQueue{
    int size;
    int start;
    int end;
    int * vet;
}tQueue;

void queuealloc(tQueue * q_queue, int size){
    q_queue -> size = size;
    // q_queue -> start = -1;
    q_queue -> start = 0;
    // q_queue -> end = -1;
    q_queue -> end = 0;
    q_queue -> vet = (int *) malloc((q_queue -> size) * sizeof(int));
}

int empty_queue(tQueue * q_queue){
    if(q_queue -> start == q_queue -> end){
        return 1;
    }
    return 0;
}

int full_queue(tQueue * q_queue){
    // if(q_queue -> end == (q_queue -> size - 1)){
    if(((q_queue -> end + 1) % (q_queue -> size)) == q_queue -> start){
        return 1;
    }
    return 0;
}

void queueprint(tQueue * q_queue){
    int i = (q_queue -> start + 1) % (q_queue -> size);

    printf("Fila F[%d]: [", q_queue -> size);
    do{
        if(i == (q_queue -> size) - 1){
            printf("%d]\n", q_queue -> vet[i]);
        }else{
            printf("%d, ", q_queue -> vet[i]);
        }

        i = (i + 1) % (q_queue -> size);
    }while(i != ((q_queue -> end + 1) % (q_queue -> size)));
}

void push(tQueue * q_queue, int elem){
    if(full_queue(q_queue)){
        printf("Fila Cheia.\n");
    }else{
        // q_queue -> end++;
        q_queue -> end = (q_queue -> end + 1) % (q_queue -> size);
        q_queue -> vet[q_queue -> end] = elem;
    }
}

int pop(tQueue * q_queue){
    int elem = -1;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        // q_queue -> start++;
        q_queue -> start = (q_queue -> start + 1) % (q_queue -> size);
        elem = q_queue -> vet[q_queue -> start];
    }

    return elem;
}

int front(tQueue * q_queue){
    int elem = -1;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        // elem = q_queue -> vet[q_queue -> ini + 1];
        elem = q_queue -> vet[(q_queue -> start + 1) % (q_queue -> size)];
    }

    return elem;
}

int back(tQueue * q_queue){
    int elem = -1;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        // elem = q_queue -> vet[q_queue -> end];
        elem = q_queue -> vet[(q_queue -> end + 1) % (q_queue -> size)];
    }

    return elem;
}
