#include <stdio.h>
#include <stdlib.h>

void countsort(int * vet, int tam){
    int max_elem, i, j;

    max_elem = vet[0];
    for(i = 0; i < tam; i++){
        if(vet[i] > max_elem){
            max_elem = vet[i];
        }
    }
    printf("    Maior Elemento de V: %d;\n", max_elem);

    int * vet_count = (int *) malloc((max_elem + 1) * sizeof(int));
    for(i = 0; i < (max_elem + 1); i++){
        vet_count[i] = 0;
    }

    for(i = 0; i < tam; i++){
        vet_count[vet[i]]++;
    }

    printf("    Vetor CONTAGEM[%d]: ", max_elem);
    for(i = 0; i < (max_elem + 1); i++){
        if(i == max_elem){
            printf("%d) %d.\n", i, vet_count[i]);
        }else{
            printf("%d) %d, ", i, vet_count[i]);
        }
    }

    i = 0;
    j = 0;
    while(j < max_elem + 1){
        if(vet_count[j] > 0){
            vet[i++] = j;
            vet_count[j]--;
        }else{
            j++;
        }
    }

    free(vet_count);
}

int main(){
    int n = 10;
    int i;
    int * vet_v = (int *) malloc(n * sizeof(int));

    vet_v[0] = 6;   vet_v[1] = 3;   vet_v[2] = 9;   vet_v[3] = 10;  vet_v[4] = 15;
    vet_v[5] = 6;   vet_v[6] = 8;   vet_v[7] = 12;  vet_v[8] = 3;   vet_v[9] = 6;

    printf("Vetor V[%d]: [", n);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet_v[i]);
        }else{
            printf("%d, ", vet_v[i]);
        }
    }

    countsort(vet_v, n);

    printf("Vetor V[%d] ORDENADO: [", n);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet_v[i]);
        }else{
            printf("%d, ", vet_v[i]);
        }
    }

    free(vet_v);
    return 0;
}
