typedef struct typeStacks{
    int size;
    int lower_top;
    int upper_top;
    int * vet;
}tStacks;

void stacksalloc(tStacks * s_stacks, int size){
    s_stacks -> size = size;
    s_stacks -> lower_top = -1;
    s_stacks -> upper_top = size;
    s_stacks -> vet = (int *) malloc((s_stacks -> size) * sizeof(int));
}

void pushes(tStacks * s_stacks, int opt, int elem){
    if(s_stacks -> upper_top == (s_stacks -> lower_top + 1)){
        printf("Pilha Cheia.\n");

        return;
    }

    if(opt == 1){
        s_stacks -> lower_top++;
        s_stacks -> vet[s_stacks -> lower_top] = elem;
    }else{
        s_stacks -> upper_top--;
        s_stacks -> vet[s_stacks -> upper_top] = elem;
    }
}

int pops(tStacks * s_stacks, int opt){
    int elem;

    if(opt == 1){
        if(s_stacks -> lower_top >= 0){
            elem = s_stacks -> vet[s_stacks -> lower_top];
            s_stacks -> lower_top--;
        }else{
            printf("Pilha '1' Vazia.\n");
        }
    }else{
        if(s_stacks -> upper_top < s_stacks -> size){
            elem = s_stacks -> vet[s_stacks -> upper_top];
            s_stacks -> upper_top++;
        }else{
            printf("Pilha '2' Vazia.\n");
        }
    }

    return elem;
}
