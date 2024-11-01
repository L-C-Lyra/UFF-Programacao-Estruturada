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

void bolha(int n, int vet[n]){
    int i, j, aux;

    for(i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

void bolha_rec(int n, int vet[n]){
    int i, aux;

    if(n == 1){
        return;
    }

    for(i = 0; i < n - 1; i++){
        if(vet[i] > vet[i + 1]){
            aux = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = aux;
        }
    }

    bolha_rec(n - 1, vet);
}

int main(){
    int n, i, opt;

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

    do{
        printf("Ordenacao da Bolha Iterativa(1) ou Recursiva(2)? ");
        scanf("%d", &opt);
    }while(opt > 2);
    if(opt == 1){
        printf("(1) Bolha Iterativa:\n");
        bolha(n, vet);
        imprime(n, vet, 0);
    }else{
        printf("(2) Bolha Recursiva:\n");
        bolha_rec(n, vet);
        imprime(n, vet, 0);
    }

    return 0;
}
