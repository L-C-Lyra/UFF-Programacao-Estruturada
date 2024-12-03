#include <limits.h>

typedef struct typeVector{
    int max_size;
    int size;
    int * vet;
}tVector;

tVector * vetalloc(int max_size){
    tVector * vet = (tVector *) malloc(sizeof(tVector));
    vet -> vet = (int *) malloc(max_size * sizeof(int));

    vet -> max_size = max_size;
    vet -> size = 0;

    return vet;
}

void vetprint(tVector * vet){
    int i;

    printf("Vetor V[%d]: [", vet -> size);
    for(i = 0; i < vet -> size; i++){
        if(i == (vet -> size) - 1){
            printf("%d]\n", vet -> vet[i]);
        }else{
            printf("%d, ", vet -> vet[i]);
        }
    }
}

void vetfree(tVector * vet){
    free(vet);
}

void vetinsert(tVector * vet){
    int pos, elem, i;

    printf("------ Inserir ------\n");

    printf("Posicao e Elemento a ser Inserido: ");
    scanf("%d %d", &pos, &elem);

    if(vet -> size < vet -> max_size){
        if((pos >= 0) && (pos <= vet -> size)){
            for(i = vet -> size; i > pos; i--){
                vet -> vet[i] = vet -> vet[i - 1];
            }

            vet -> vet[pos] = elem;
            vet -> size++;

            vetprint(vet);
        }else{
            printf("Posicao Invalida.\n");
        }
    }else{
        printf("Nao ha ESPACO no Vetor V.\n");
    }

    printf("---------------------\n");
}

void vetadd(tVector * vet){
    int elem;

    printf("----- Adicionar -----\n");

    printf("Elemento a ser Adicionado: ");
    scanf("%d", &elem);

    if(vet -> size < vet -> max_size){
        vet -> vet[vet -> size] = elem;
        vet -> size++;

        vetprint(vet);
    }else{
        printf("Nao ha ESPACO no Vetor V.\n");
    }

    printf("---------------------\n");
}

void vetremove(tVector * vet){
    int pos, i;

    printf("------ Remover ------\n");

    printf("Posicao a ser Removida: ");
    scanf("%d", &pos);

    if(vet -> size > 0){
        if((vet -> size > pos) && (pos >= 0)){
            for(i = pos; i < (vet -> size) - 1; i++){
                vet -> vet[i] = vet -> vet[i + 1];
            }
            vet -> size--;

            vetprint(vet);
        }else{
            printf("Posicao Invalida.\n");
        }
    }else{
        printf("Vetor V se encontra VAZIO.\n");
    }

    printf("---------------------\n");
}

void smart_search(tVector * vet){
    int elem, i, temp;
    int aux = 0;

    printf("- Busca Inteligente -\n");

    printf("Elemento a ser Buscado: ");
    scanf("%d", &elem);

    if(vet -> size > 0){
        for(i = 0; i < vet -> size; i++){
            aux++;
            if(vet -> vet[i] == elem){
                printf("Elemento %d se encontra na Posicao %d (%d Testes Efetuados).\n", elem, i, aux);

                if(i - 1 >= 0){
                    temp              = vet -> vet[i - 1];
                    vet -> vet[i - 1] = vet -> vet[i];
                    vet -> vet[i]     = temp;
                }

                return;
            }
        }
    }else{
        printf("Vetor V se encontra VAZIO.\n");
    }

    printf("Elemento %d NAO Encontrado (%d Testes Efetuados).\n", elem, aux);
    printf("---------------------\n");
}

void vetreverse(tVector * vet){
    int i, j, temp;

    printf("----- Inverter ------\n");

    if(vet -> size > 0){
        for(i = 0, j = (vet -> size) - 1; i < j; i++, j--){
            temp          = vet -> vet[i];
            vet -> vet[i] = vet -> vet[j];
            vet -> vet[j] = temp;
        }

        vetprint(vet);
    }else{
        printf("Vetor V se encontra VAZIO.\n");
    }

    printf("---------------------\n");
}

void rotate_left(tVector * vet){
    int rot, ind, last, i;

    printf("----  Rotacionar ----\n");

    printf("Quantas rotacoes? ");
    scanf("%d", &rot);

    if(vet -> size > 0){
        ind = 1;
        while(ind <= rot){
            last = vet -> vet[0];
            for(i = 0; i < (vet -> size) - 1; i++){
                vet -> vet[i] = vet -> vet[i + 1];
            }
            vet -> vet[(vet -> size) - 1] = last;

            ind++;

            vetprint(vet);
        }
    }else{
        printf("Vetor V se encontra VAZIO.\n");
    }

    printf("---------------------\n");
}

void vetsort(tVector * vet){
    int i, j, temp;

    printf("------ Ordenar ------\n");

    for(i = 0; i < vet -> size; i++){
        for(j = 0; j < (vet -> size) - 1; j++){
            if(vet -> vet[j] > vet -> vet[j + 1]){
                temp              = vet -> vet[j];
                vet -> vet[j]     = vet -> vet[j + 1];
                vet -> vet[j + 1] = temp;
            }
        }
    }

    vetprint(vet);

    printf("---------------------\n");
}

void duplicates(tVector * vet){
    int i;
    int last_dup = INT_MAX;

    printf("----  Duplicatas ----\n");

    printf("Duplicatas: ");
    for(i = 0; i < vet -> size; i++){
        if((vet -> vet[i] == vet -> vet[i + 1]) && (vet -> vet[i] != last_dup)){
            printf("%4d", vet -> vet[i]);
            last_dup = vet -> vet[i];
        }
    }
    printf("\n");

    printf("---------------------\n");
}

void even_sum(tVector * vet){
    int i, maximum, sum;

    printf("----- Soma Par ------\n");

    printf("Soma = ");
    scanf("%d", &sum);

    printf("Valor Maximo = ");
    scanf("%d", maximum);

    int * vet_aux = (int *) malloc((maximum + 1) * sizeof(int));
    for(i = 0; i < maximum; i++){
        vet_aux[i] = 0;
    }

    for(i = 0; i < vet -> size; i++){
        if((sum - (vet -> vet[i]) >= 0) && (sum - (vet -> vet[i]) < maximum)){
            if(vet_aux[sum - (vet -> vet[i])] != 0){
                printf("    %d + %d = %d\n", vet -> vet[i], sum - (vet -> vet[i]), sum);
            }
        }

        vet_aux[vet -> vet[i]]++;
    }

    printf("---------------------\n");

    free(vet_aux);
}
