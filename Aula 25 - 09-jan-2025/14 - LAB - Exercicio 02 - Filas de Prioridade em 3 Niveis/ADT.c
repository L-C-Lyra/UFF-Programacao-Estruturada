typedef struct typeStack{
    int size;
    int top;
    int * vet;
}tStack;

void stackalloc(tStack * s_stack, int size){
    s_stack -> size = size;
    s_stack -> top = -1;
    s_stack -> vet = (int *) malloc((s_stack -> size) * sizeof(int));
}

int empty_stack(tStack * s_stack){
    if(s_stack -> top == -1){
        return 1;
    }
    return 0;
}

int full_stack(tStack * s_stack){
    if(s_stack -> top == (s_stack -> size - 1)){
        return 1;
    }
    return 0;
}

void stackprint(tStack * s_stack){
    int i;

    printf("Pilha P[%d]: [", s_stack -> top + 1);
    for(i = s_stack -> top; i >= 0; i--){
        if(i == 0){
            printf("%d]\n", s_stack -> vet[i]);
        }else{
            printf("%d, ", s_stack -> vet[i]);
        }
    }
}

void push_stack(tStack * s_stack, int elem){
    if(s_stack -> top < (s_stack -> size - 1)){
        s_stack -> top++;
        s_stack -> vet[s_stack -> top] = elem;
    }else{
        printf("Pilha Cheia.\n");
    }
}

int pop_stack(tStack * s_stack){
    int elem = -1;

    if(s_stack -> top >= 0){
        elem = s_stack -> vet[s_stack -> top];
        s_stack -> top--;
    }else{
        printf("Pilha Vazia.\n");
    }

    return elem;
}

int top_stack(tStack * s_stack){
    int elem = -1;

    if(s_stack -> top >= 0){
        elem = s_stack -> vet[s_stack -> top];
    }else{
        printf("Pilha Vazia.\n");
    }

    return elem;
}

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

int empty_queues(tQueue * q_q_a, tQueue * q_q_b, tQueue * q_q_c){
    if((q_q_a -> start == NULL) &&
       (q_q_b -> start == NULL) &&
       (q_q_c -> start == NULL)){
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

void queuesprint(tQueue * q_q_a, tQueue * q_q_b, tQueue * q_q_c){
    tNode * node;
    node = q_q_a -> start;

    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
    }node = q_q_b -> start;
    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
    }node = q_q_c -> start;
    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
    }
}

void push_queue(tQueue * q_queue, int elem){
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

void push_queues(tQueue * q_q_a, tQueue * q_q_b, tQueue * q_q_c, int elem, int prio){
    if(prio == 1){
        push_queue(q_q_a, elem);
    }else if(prio == 2){
        push_queue(q_q_b, elem);
    }else if(prio == 3){
        push_queue(q_q_c, elem);
    }
}

int pop_queue(tQueue * q_queue){
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

int pop_queues(tQueue * q_q_a, tQueue * q_q_b, tQueue * q_q_c){
    int elem = -1;
    tNode * node;

    if(empty_queue(q_q_a)){
        if(empty_queue(q_q_b)){
            if(empty_queue(q_q_c)){
                printf("Fila Vazia.\n");
            }else{
                elem = q_q_c -> start -> info;
                node = q_q_c -> start;
                q_q_c -> start = q_q_c -> start -> next_node;
                free(node);
            }
        }else{
            elem = q_q_b -> start -> info;
            node = q_q_b -> start;
            q_q_b -> start = q_q_b -> start -> next_node;
            free(node);
        }
    }else{
        elem = q_q_a -> start -> info;
        node = q_q_a -> start;
        q_q_a -> start = q_q_a -> start -> next_node;
        free(node);
    }

    return elem;
}

int top_queue(tQueue * q_queue){
    int elem = -1;

    if(empty_queue(q_queue)){
        printf("Fila Vazia.\n");
    }else{
        elem = q_queue -> start -> info;
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
