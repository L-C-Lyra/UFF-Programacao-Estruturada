#include <stdio.h>
#include <stdlib.h>

int particao(int * vet, int ini, int fim){
    int pivot, i, f, temp;

    pivot = vet[ini];
    i = ini;
    f = fim;

    while(i < f){
        while((i <= fim) && (vet[i] < pivot)){
            i++;
        }
        while((f >= ini) && (vet[f] > pivot)){
            f--;
        }

        if(i < f){
            temp = vet[i];
            vet[i] = vet[f];
            vet[f] = temp;
        }
    }

    temp = vet[f];
    vet[f] = vet[ini];
    vet[ini] = temp;

    return f;
}

void quicksort(int * vet, int ini, int fim){
    int p;

    if(ini < fim){
        p = particao(vet, ini, fim);

        quicksort(vet, ini, p - 1);
        quicksort(vet, p + 1, fim);
    }
}

int main(){
    int n = 7;
    int i;
    int * vet_v = (int *) malloc(n * sizeof(int));

    vet_v[0] = 3;   vet_v[1] = 6;   vet_v[2] = 4;   vet_v[3] = 5;
    vet_v[4] = 1;   vet_v[5] = 7;   vet_v[6] = 2;

    printf("Vetor V[%d]: [", n);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet_v[i]);
        }else{
            printf("%d, ", vet_v[i]);
        }
    }

    quicksort(vet_v, 0, n - 1);

    printf("Vetor V[%d] ORDENADO: [", n);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]", vet_v[i]);
        }else{
            printf("%d, ", vet_v[i]);
        }
    }

    free(vet_v);
    return 0;
}
