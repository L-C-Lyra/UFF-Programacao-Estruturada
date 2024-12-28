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

void push(tStack * s_stack, int elem){
    if(s_stack -> top < (s_stack -> size - 1)){
        s_stack -> top++;
        s_stack -> vet[s_stack -> top] = elem;
    }else{
        printf("Pilha Cheia.\n");
    }
}

int pop(tStack * s_stack){
    int elem;

    if(s_stack -> top >= 0){
        elem = s_stack -> vet[s_stack -> top];
        s_stack -> top--;
    }else{
        printf("Pilha Vazia.\n");
    }

    return elem;
}

int top(tStack * s_stack){
    int elem;

    if(s_stack -> top >= 0){
        elem = s_stack -> vet[s_stack -> top];
    }else{
        printf("Pilha Vazia.\n");
    }

    return elem;
}

void pos_stackswap(tStack * s_stack, int pos, int elem){
    int i;
    int size = s_stack -> top;
    tStack temp;
    stackalloc(&temp, s_stack -> top + 1);

    if(pos > s_stack -> top){
        printf("Posicao Invalida.\n");

        return;
    }

    for(i = 0; i < (size - pos); i++){
        int popped_elem = pop(s_stack);

        push(&temp, popped_elem);
    }

    pop(s_stack);

    push(s_stack, elem);

    for(i = 0; i < (size - pos); i++){
        int popped_elem = pop(&temp);

        push(s_stack, popped_elem);
    }
}
