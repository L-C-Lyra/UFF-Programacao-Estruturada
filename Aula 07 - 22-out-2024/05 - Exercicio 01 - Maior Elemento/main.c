#include <stdio.h>
#include <stdlib.h>

int menor_ele(int n, int v[n]){
    int i;
    int menor_n = v[0];

    for(i = 0; i < n; i++){
        if(v[i] < menor_n){
            menor_n = v[i];
        }
    }
    printf("Menor Elemento = %d", menor_n);

    printf("\nNovo Vetor = [");
    for(i = 0; i < n; i++){
        v[i] -= menor_n;

        if(i == n - 1){
            printf("%d]", v[i]);
        }else{
            printf("%d, ", v[i]);
        }
    }

    return menor_n;
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

    menor_ele(n, v);

    return 0;
}
