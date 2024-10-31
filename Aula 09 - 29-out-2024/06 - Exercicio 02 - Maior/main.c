#include <stdio.h>
#include <stdlib.h>

int maior(int v[], int ini, int fim){
    int aux;

    if(ini == fim){
        return v[fim];
    }

    aux = maior(v, ini + 1, fim);

    if(v[ini] > aux){
        return v[ini];
    }

    return aux;
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
    printf("\nMaior = %d", maior(v, 0, n - 1));

    return 0;
}
