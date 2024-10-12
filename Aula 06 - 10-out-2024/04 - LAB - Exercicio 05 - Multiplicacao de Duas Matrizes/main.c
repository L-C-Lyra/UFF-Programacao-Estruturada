#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n, p, i, j, x;

    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    printf("p: ");
    scanf("%d", &p);

    float mat_a[n][m];
    float mat_b[m][p];
    float mat_mul[n][p];

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &mat_a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < p; j++){
            printf("B[%d][%d] = ", i, j);
            scanf("%f", &mat_b[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            mat_mul[i][j] = 0;
            for(x = 0; x < m; x++){
                mat_mul[i][j] += mat_a[i][x] * mat_b[x][j];
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            printf("C[%d][%d] = %.0f", i, j, mat_mul[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
