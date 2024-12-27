#include <stdio.h>
#include <stdlib.h>

void busca_binaria(int * vet, int tam, int elem){
    int ini, mei, fim;

    ini = 0;
    fim = tam - 1;
    mei = ini + (fim - ini) / 2;

    while(ini <= fim){
        if(vet[mei] == elem){
            printf("Elemento %d se encontra na(s) Posicao(oes) %d", elem, mei);

            int ant = mei - 1;
            while(ant >= 0){
                if(vet[ant] == elem){
                    printf(", %d", ant);
                }else{
                    break;
                }
                ant--;
            }

            int pos = mei + 1;
            while(pos < tam){
                if(vet[pos] == elem){
                    printf(", %d", pos);
                }else{
                    break;
                }
                pos++;
            }

            printf(".");
            return;
        }else if(vet[mei] < elem){
            ini = mei + 1;
            mei = ini + (fim - ini) / 2;
        }else if(vet[mei] > elem){
            fim = mei - 1;
            mei = ini + (fim - ini) / 2;
        }
    }

    printf("Elemento %d NAO encontrado.", elem);
    return;
}

int main(){
    int n = 8;
    int i, elem;
    int * vet_v = (int *) malloc(n * sizeof(int));

    vet_v[0] = 1;   vet_v[1] = 1;   vet_v[2] = 5;   vet_v[3] = 5;
    vet_v[4] = 5;   vet_v[5] = 8;   vet_v[6] = 8;   vet_v[7] = 8;

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

    busca_binaria(vet_v, n, elem);

    free(vet_v);
    return 0;
}
