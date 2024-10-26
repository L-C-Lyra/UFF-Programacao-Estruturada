#include <stdio.h>
#include <stdlib.h>

void lematriz(int m, int n, int mat[m][n]){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
}

void imprimematriz(int m, int n, int mat[m][n]){
    int i, j;

    printf("Matriz A(%dx%d) = \n", m, n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

int elem_lin(int m, int n, int mat[m][n], int elem, int lin){
    int j;

    for(j = 0; j < n; j++){
        if(mat[lin][j] == elem){
            return 1;
        }
    }
    return 0;
}

int elem_col(int m, int n, int mat[m][n], int elem, int col){
    int i;

    for(i = 0; i < m; i++){
        if(mat[i][col] == elem){
            return 1;
        }
    }
    return 0;
}

int latina(int m, int n, int mat[m][n]){
    int i, j, elem;

    for(i = 0; i < m; i++){
        for(elem = 1; elem <= m; elem++){
            if(!(elem_lin(m, n, mat, elem, i))){
                return 0;
            }
        }
    }
    for(j = 0; j < n; j++){
        for(elem = 1; elem <= n; elem++){
            if(!(elem_col(m, n, mat, elem, j))){
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    int n, latino;

    printf("n: ");
    scanf("%d", &n);

    int mat[n][n];

    lematriz(n, n, mat);
    imprimematriz(n, n, mat);

    latino = latina(n, n, mat);
    if(latino){
        printf("EH um Quadrado Latino.");
    }else{
        printf("NAO EH um Quadrado Latino.");
    }

    return 0;
}
