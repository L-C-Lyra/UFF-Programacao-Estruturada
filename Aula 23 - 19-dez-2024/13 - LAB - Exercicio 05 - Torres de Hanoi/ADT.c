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

void han_stackprint(tStack * s_s_a, tStack * s_s_b, tStack * s_s_c, int n){
    int i;

    for(i = (n - 1); i >= 0; i--){
        if(s_s_a -> top >= i){
            printf("| %3d |\t\t", s_s_a -> vet[i]);
        }else{
            printf("|     |\t\t");
        }

        if(s_s_b -> top >= i){
            printf("| %3d |\t\t", s_s_b -> vet[i]);
        }else{
            printf("|     |\t\t");
        }

        if(s_s_c -> top >= i){
            printf("| %3d |\n", s_s_c -> vet[i]);
        }else{
            printf("|     |\n");
        }
    }
    printf("\n|--A--|\t\t|--B--|\t\t|--C--|\n\n");
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

void move_between_hanoi_towers(tStack * s_src, tStack * s_dest){
    if(empty_stack(s_dest) && !empty_stack(s_src)){
        push(s_dest, pop(s_src));
    }else if(empty_stack(s_src) && !empty_stack(s_dest)){
        push(s_src, pop(s_dest));
    }else if (top(s_src) < top(s_dest)){
        push(s_dest, pop(s_src));
    }else{
        push(s_src, pop(s_dest));
    }
}

void hanoi_towers(tStack * s_s_a, tStack * s_s_b, tStack * s_s_c, int n){
    int steps;

    steps = 0;
    while((s_s_b -> top < (n - 1)) && (s_s_c -> top < (n - 1))){
        if((!empty_stack(s_s_a)) || (!empty_stack(s_s_b))){
            steps++;
            printf("Passo %2d: Mova-se entre A e B.\n", steps);

            move_between_hanoi_towers(s_s_a, s_s_b);

            han_stackprint(s_s_a, s_s_b, s_s_c, n);
        }

        if((!empty_stack(s_s_a)) || (!empty_stack(s_s_c))){
            steps++;
            printf("Passo %2d: Mova-se entre A e C.\n", steps);

            move_between_hanoi_towers(s_s_a, s_s_c);

            han_stackprint(s_s_a, s_s_b, s_s_c, n);
        }

        if((!empty_stack(s_s_b)) || (!empty_stack(s_s_c))){
            steps++;
            printf("Passo %2d: Mova-se entre B e C.\n", steps);

            move_between_hanoi_towers(s_s_b, s_s_c);

            han_stackprint(s_s_a, s_s_b, s_s_c, n);
        }
    }
}
