#include <stdio.h>
#include <stdlib.h>

void rota_1_direita(int * vet, int n){
    int i, n_minus_one;

    n_minus_one = vet[n - 1];

    for(i = n - 1; i > 0; i--){
        vet[i] = vet[i - 1];
    }

    vet[0] = n_minus_one;
}

int main(){
    int n, k, i;
    int * vet;

    printf("n: ");
    scanf("%d", &n);

    printf("k: ");
    scanf("%d", &k);

    vet = (int *) malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        printf("N[%d] = ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");

    printf("Vetor = [");
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet[i]);
        }else{
            printf("%d, ", vet[i]);
        }
    }

    for(i = 1; i <= k; i++){
        rota_1_direita(vet, n);
    }

    printf("Rotev (Em %d Posicoes) = [", k);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]", vet[i]);
        }else{
            printf("%d, ", vet[i]);
        }
    }

    free(vet);
    return 0;
}
