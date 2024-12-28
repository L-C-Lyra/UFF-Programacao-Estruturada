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

int is_equals_char(char c_1, char c_2){
    if(((c_1 == '(') && (c_2 == ')')) ||
       ((c_1 == '[') && (c_2 == ']')) ||
       ((c_1 == '{') && (c_2 == '}'))){
        return 1;
    }
    return 0;
}

int is_balanced_exp(char * exp, int len){
    int i;
    tStack temp;
    stackalloc(&temp, len + 1);

    for(i = 0; i < len; i++){
        if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')){
            printf("%c", exp[i]);

            push(&temp, exp[i]);
        }else if((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')){
            printf("%c", exp[i]);

            if(empty_stack(&temp)){
                printf(" <- ERRO!\n");

                return 0;
            }else if(!is_equals_char(pop(&temp), exp[i])){
                printf(" <- ERRO!\n");

                return 0;
            }
        }
    }

    if(empty_stack(&temp)){
        printf(" <- ACERTO!\n");

        return 1;
    }

    printf(" <- ERRO!\n");

    return 0;
}
