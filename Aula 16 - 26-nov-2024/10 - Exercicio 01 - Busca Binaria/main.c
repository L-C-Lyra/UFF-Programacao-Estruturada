#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int * vet, int tam, int elem){
    int ini, mei, fim;

    ini = 0;
    fim = tam - 1;
    mei = (ini + fim) / 2;

    while(ini <= fim){
        if(vet[mei] == elem){
            return mei;
        }else if(vet[mei] < elem){
            ini = mei + 1;
            mei = (ini + fim) / 2;
        }else if(vet[mei] > elem){
            fim = mei - 1;
            mei = (ini + fim) / 2;
        }
    }

    return -1;
}

int main(){
    int n = 8;
    int i, elem, pos;
    int * vet_v = (int *) malloc(n * sizeof(int));

    vet_v[0] = 4;   vet_v[1] = 10;  vet_v[2] = 80;    vet_v[3] = 90;
    vet_v[4] = 91;  vet_v[5] = 99;  vet_v[6] = 100;   vet_v[7] = 101;

    printf("Vetor V[%d]: [", n);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet_v[i]);
        }else{
            printf("%d, ", vet_v[i]);
        }
    }

    printf("Elemento a ser Buscado: ");
    scanf("%d", &elem);

    pos = busca_binaria(vet_v, n, elem);

    if(pos == -1){
        printf("Elemento %d NAO encontrado.", elem);
    }else{
        printf("Elemento %d se encontra na Posicao %d.", elem, pos);
    }

    free(vet_v);
    return 0;
}
