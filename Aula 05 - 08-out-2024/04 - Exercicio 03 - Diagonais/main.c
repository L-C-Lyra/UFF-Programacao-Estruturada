#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j, aux;

    printf("n: ");
    scanf("%d", &n);

    int mat[n][n];

    printf("Digite os Valores da Matriz de n: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        aux = mat[i][i];
        mat[i][i] = mat[i][(n - i) - 1];
        mat[i][(n - i) - 1] = aux;
    }

    printf("\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j < n - 1){
                printf("%d ", mat[i][j]);
            }else{
                printf("%d", mat[i][j]);
            }
        }
        if(i < n - 1){
            printf("\n");
        }
    }

    return 0;
}
