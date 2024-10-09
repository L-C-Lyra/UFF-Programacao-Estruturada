#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n, i, j;
    int cont = 0;

    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    int vet_m[m];
    int vet_n[n];

    for(i = 0; i < m; i++){
        printf("A[%d] = ", i);
        scanf("%d", &vet_m[i]);
    }

    for(i = 0; i < n; i++){
        printf("B[%d] = ", i);
        scanf("%d", &vet_n[i]);
    }

    printf("\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(vet_m[i] == vet_n[j]){
                printf("%d\n", vet_m[i]);
                cont++;
            }
        }
    }

    printf("\n%d numero(s) repetidos.", cont);

    return 0;
}
