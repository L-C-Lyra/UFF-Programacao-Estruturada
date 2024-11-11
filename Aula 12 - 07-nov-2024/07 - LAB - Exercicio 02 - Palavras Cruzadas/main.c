#include <stdio.h>
#include <stdlib.h>

int ** matalloc(int m, int n){
    int i;
    int ** mat;

    mat = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < n; i++){
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

void matprint(int m, int n, int ** mat){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

int start_word(int m, int n, int ** mat, int i, int j){
    // Palavra HORIZONTAL:
    if((mat[i][j] != -1) && ((j == 0) || (mat[i][j - 1] == -1)) && ((j + 1 < n) && (mat[i][j + 1] == 0))){
    //  Posição Livre    && Início de Palavra HORIZONTAL        && Ter MAIS de 02 Caracteres.
        return 1;
    }

    // Palavra VERTICAL:
    if((mat[i][j] != -1) && ((i == 0) || (mat[i - 1][j] == -1)) && ((i + 1 < m) && (mat[i + 1][j] == 0))){
    //  Posição Livre    && Início de Palavra VERTICAL          && Ter MAIS de 02 Caracteres.
        return 1;
    }

    return 0;
}

int main(){
    int m = 5;
    int n = 8;
    int i, j, aux;
    int ** mat_a = matalloc(m, n);

    mat_a[0][0] = 0;    mat_a[0][1] = -1;   mat_a[0][2] = 0;    mat_a[0][3] = -1;
    mat_a[1][0] = 0;    mat_a[1][1] = 0;    mat_a[1][2] = 0;    mat_a[1][3] = 0;
    mat_a[2][0] = 0;    mat_a[2][1] = 0;    mat_a[2][2] = -1;   mat_a[2][3] = -1;
    mat_a[3][0] = -1;   mat_a[3][1] = 0;    mat_a[3][2] = 0;    mat_a[3][3] = 0;
    mat_a[4][0] = 0;    mat_a[4][1] = 0;    mat_a[4][2] = -1;   mat_a[4][3] = 0;

    mat_a[0][4] = -1;   mat_a[0][5] = 0;    mat_a[0][6] = -1;   mat_a[0][7] = 0;
    mat_a[1][4] = -1;   mat_a[1][5] = 0;    mat_a[1][6] = 0;    mat_a[1][7] = 0;
    mat_a[2][4] = 0;    mat_a[2][5] = 0;    mat_a[2][6] = -1;   mat_a[2][7] = 0;
    mat_a[3][4] = 0;    mat_a[3][5] = -1;   mat_a[3][6] = 0;    mat_a[3][7] = 0;
    mat_a[4][4] = 0;    mat_a[4][5] = 0;    mat_a[4][6] = -1;   mat_a[4][7] = -1;

    printf("Palavras Cruzadas em Matriz: \n");
    matprint(m, n, mat_a);

    aux = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(start_word(m, n, mat_a, i, j)){
                aux++;
                mat_a[i][j] = aux;
            }
        }
    }

    printf("Posicoes das Palavras nas Palavras Cruzadas em Matriz: \n");
    matprint(m, n, mat_a);

    matfree(m, n, mat_a);
    return 0;
}
