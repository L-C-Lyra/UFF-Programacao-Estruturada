#include <stdio.h>
#include <stdlib.h>

void imprime(int n, int vet[n], int i){
    if(i == 0){
        printf("v = [%d, ", vet[0]);
        imprime(n, vet, 1);
    }else if(i == n - 1){
        printf("%d]", vet[i]);
        return;
    }else{
        printf("%d, ", vet[i]);
        imprime(n, vet, i + 1);
    }
}

void inverte(int n, int vet[n], int ini, int fim){
    int aux;

    if(ini >= fim){
        return;
    }

    aux = vet[ini];
    vet[ini] = vet[fim];
    vet[fim] = aux;

    inverte(n, vet, ini + 1, fim - 1);
}

int main(){
    int n, i;

    printf("n: ");
    scanf("%d", &n);

    int vet[n];

    for(i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");

    printf("Vetor:\n");
    imprime(n, vet, 0);
    printf("\n");

    printf("Rotev:\n");
    inverte(n, vet, 0, n - 1);
    imprime(n, vet, 0);

    return 0;
}
