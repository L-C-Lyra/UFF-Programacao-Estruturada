#include <stdio.h>
#include <stdlib.h>

int indice_min(int n, int v[n], int k){
    int i;
    int ind = k;
    int ind_min = v[k];

    for(i = k + 1; i < n; i++){
        if(ind_min > v[i]){
            ind_min = v[i];
            ind = i;
        }
    }

    return ind;
}

void ordena(int n, int v[n]){
    int i, ind, aux;

    for(i = 0; i < n; i++){
        ind = indice_min(n, v, i);

        aux = v[i];
        v[i] = v[ind];
        v[ind] = aux;
    }
}

int main(){
    int n, i;

    printf("n: ");
    scanf("%d", &n);

    int v[n];

    for(i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    printf("\n");

    printf("Vetor = [");
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", v[i]);
        }else{
            printf("%d, ", v[i]);
        }
    }

    ordena(n, v);

    printf("Vetor Ordenado = [");
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]", v[i]);
        }else{
            printf("%d, ", v[i]);
        }
    }

    return 0;
}
