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

/*
int full_stack(tStack * s_stack){
    if(s_stack -> top == (s_stack -> size - 1)){
        return 1;
    }
    return 0;
}
*/

/*
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
*/

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

/*
int top(tStack * s_stack){
    int elem;

    if(s_stack -> top >= 0){
        elem = s_stack -> vet[s_stack -> top];
    }else{
        printf("Pilha Vazia.\n");
    }

    return elem;
}
*/

// Is required to use THIS PROTOTYPE:
int pilhasIguais(tStack * p1, int tam1, tStack * p2, int tam2){
    if(tam1 != tam2){
        return 0;
    }

    int val1, val2;
    tStack aux1;
    tStack aux2;
    stackalloc(&aux1, tam1);
    stackalloc(&aux2, tam2);

    int iguais = 1;
    while(!empty_stack(p1) && iguais){
        val1 = pop(p1);
        val2 = pop(p2);

        if(val1 != val2){
            iguais = 0;
        }

        push(&aux1, val1);
        push(&aux2, val2);
    }

    while(!empty_stack(&aux1)){
        val1 = pop(&aux1);
        push(p1, val1);
    }while(!empty_stack(&aux2)){
        val2 = pop(&aux2);
        push(p2, val2);
    }

    return iguais;
}
