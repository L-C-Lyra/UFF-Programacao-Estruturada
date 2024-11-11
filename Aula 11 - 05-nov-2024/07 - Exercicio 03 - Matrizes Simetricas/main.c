#include <stdio.h>
#include <stdlib.h>

int simetrica(int ** mat, int m, int n){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(mat[i][j] != mat[j][i]){
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    int m, n, i, j;

    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    if(m != n){
        printf("A Matriz M NAO EH Simetrica.");

        return 0;
    }

    float ** mat_m;

    mat_m = (float **) malloc(m * sizeof(float *));
    for(i = 0; i < n; i++){
        mat_m[i] = (float *) malloc(n * sizeof(float));
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("M[%d][%d] = ", i, j);
            scanf("%f", &mat_m[i][j]);
        }
        printf("\n");
    }

    if(simetrica(mat_m, m, n)){
        printf("A Matriz M EH Simetrica.");
    }else{
        printf("A Matriz M NAO EH Simetrica.");
    }

    for(i = 0; i < n; i++){
        free(mat_m[i]);
    }
    free(mat_m);
    return 0;
}
