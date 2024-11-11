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
            scanf("%f", &mat[i][j]);
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

void vetprint(int m, int * vet){
    int i;

    printf("[");
    for(i = 0; i < m; i++){
        if(i == m - 1){
            printf("%d]", vet[i]);
        }else{
            printf("%d, ", vet[i]);
        }
    }
}

int main(){
    int k_1, k_2, i, j;
    int ** mat_a = matalloc(4, 4);

    mat_a[0][0] = 0;    mat_a[0][1] = 4;    mat_a[0][2] = 9;    mat_a[0][3] = 3;
    mat_a[1][0] = 5;    mat_a[1][1] = 0;    mat_a[1][2] = 1;    mat_a[1][3] = 400;
    mat_a[2][0] = 2;    mat_a[2][1] = 1;    mat_a[2][2] = 0;    mat_a[2][3] = 8;
    mat_a[3][0] = 7;    mat_a[3][1] = 5;    mat_a[3][2] = 2;    mat_a[3][3] = 0;

    printf("A: \n");
    matprint(4, 4, mat_a);

    printf("\nk1: ");
    scanf("%d", &k_1);

    printf("k2: ");
    scanf("%d", &k_2);

    int * it = (int *) malloc(k_2 * sizeof(int));

    for(i = 0; i < k_1; i++){
        printf("\nItinerario %d: \n", i + 1);

        for(j = 0; j < k_2; j++){
            printf("    Cidade %d: ", j + 1);
            scanf("%d", &it[j]);
        }

        int it_cost = 0;
        for(j = 0; j < k_2 - 1; j++){
            it_cost += mat_a[it[j]][it[j + 1]];
        }
        printf("Custo do Itinerario %d = %d.", i + 1, it_cost);
        if(i != k_1 - 1){
            printf("\n");
        }
    }

    matfree(4, 4, mat_a);
    free(it);
    return 0;
}
