#include <stdio.h>
#include <stdlib.h>

int ** matalloc(int m, int n){
    int i;
    int ** mat;

    mat = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < m; i++){
        mat[i] = (int *) malloc(n * sizeof(int));
    }

    return mat;
}

void matfree(int m, int n, int ** mat){
    int i;

    for(i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
}

void matread(int m, int n, int ** mat){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m, max_m, n, i, j;
    int ** mat;
    int * MAX;

    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    mat = matalloc(m, n);
    MAX = (int *) malloc(m * sizeof(int));

    matread(m, n, mat);

    for(i = 0; i < m; i++){
        max_m = mat[i][0];
        for(j = 0; j < n; j++){
            if(mat[i][j] > max_m){
                max_m = mat[i][j];
            }
        }
        MAX[i] = max_m;

        printf("MAX[%d] = %d", i, MAX[i]);
        if(!(i == m - 1)){
            printf("\n");
        }
    }

    matfree(m, n, mat);
    free(MAX);
    return 0;
}
