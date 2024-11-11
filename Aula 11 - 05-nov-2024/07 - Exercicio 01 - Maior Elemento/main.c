#include <stdio.h>
#include <stdlib.h>

int largest_element(int *vet, int n, int i){
    if(i == n - 1){
        return vet[i];
    }

    int largest = largest_element(vet, n, i + 1);

    if(vet[i] > largest){
        return vet[i];
    }

    return largest;
}

int main(){
    int n, i;
    int * vet;

    printf("n: ");
    scanf("%d", &n);

    vet = (int *) malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        printf("N[%d] = ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");

    printf("Maior Elemento de N = %d", largest_element(vet, n, 0));

    free(vet);
    return 0;
}
