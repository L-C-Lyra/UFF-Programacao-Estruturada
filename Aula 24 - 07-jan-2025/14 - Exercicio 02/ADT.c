typedef struct typeNode{
    int info;
    struct typeNode * next_node;
}tNode;

typedef struct typeQueue{
    struct typeNode * start;
    struct typeNode * end;
}tQueue;

tNode * nodealloc(){
    tNode * temp;
    temp = (tNode *) malloc(sizeof(tNode));
    temp -> next_node = NULL;

    return temp;
}

tQueue * queuealloc(){
    tQueue * temp;
    temp = (tQueue *) malloc(sizeof(tQueue));
    temp -> start = NULL;
    temp -> end = NULL;

    return temp;
}

int empty_queue(tQueue * q_queue){
    if(q_queue -> start == NULL){
        return 1;
    }
    return 0;
}

void queueprint(tQueue * q_queue){
    tNode * node;
    node = q_queue -> start;

    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
    }
}

void push(tQueue * q_queue, int elem){
    tNode * new_node;
    new_node = nodealloc();
    new_node -> info = elem;

    if(empty_queue(q_queue)){
        q_queue -> start = new_node;
        q_queue -> end = new_node;
    }else{
        q_queue -> end -> next_node = new_node;
        q_queue -> end = new_node;
    }
}

int pop(tQueue * q_queue){
    int elem = -1;
    tNode * node;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        elem = q_queue -> start -> info;
        node = q_queue -> start;
        q_queue -> start = q_queue -> start -> next_node;
        free(node);
    }

    return elem;
}

tQueue * queuefree(tQueue * q_queue){
    tNode * node = q_queue -> start;

    while(node != NULL){
        tNode * temp = node -> next_node;
        free(node);
        node = temp;
    }
    free(q_queue);

    return NULL;
}
