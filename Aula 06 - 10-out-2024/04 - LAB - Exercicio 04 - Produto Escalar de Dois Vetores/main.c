#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i;
    int dot_prod = 0;

    printf("n: ");
    scanf("%d", &n);

    int vet_x[n];
    int vet_y[n];

    for(i = 0; i < n; i++){
        printf("X[%d] = ", i);
        scanf("%d", &vet_x[i]);
    }

    for(i = 0; i < n; i++){
        printf("Y[%d] = ", i);
        scanf("%d", &vet_y[i]);
    }

    for(i = 0; i < n; i++){
        dot_prod += vet_x[i] * vet_y[i];
    }

    printf("\nX . Y = %d", dot_prod);

    return 0;
}
