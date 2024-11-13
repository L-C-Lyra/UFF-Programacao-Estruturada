#include <stdio.h>
#include <stdlib.h>

int vetsum_rec(int n, int i, int * vet){
    if(i == n - 1){
        return vet[i];
    }

    return vet[i] + vetsum_rec(n, i + 1, vet);
}

int main(){
    int n, i;
    int * vet;

    printf("n: ");
    scanf("%d", &n);

    vet = (int *) malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        printf("V[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    printf("\nSoma(V) = %d", vetsum_rec(n, 0, vet));

    free(vet);
    return 0;
}
