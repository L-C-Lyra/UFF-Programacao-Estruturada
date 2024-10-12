#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, n_seq, i, j, aux = 0;

    printf("n: ");
    scanf("%d", &n);

    int vet_seq[n];

    for(i = 0; i < n; i++){
        printf("Seq[%d] = ", i);
        scanf("%d", &vet_seq[i]);
    }
    printf("\n");

    aux = 0;
    for(n_seq = 1; (!aux) && (n_seq <= n); n_seq++){
        for(i = 0; (!aux) && (i <= n - (2 * n_seq)); i++){
            aux = 1;
            for(j = 0; aux && (j < n_seq); j++){
                if(vet_seq[i + j] != vet_seq[i + j + n_seq]){
                    aux = 0;
                }
            }
        }
    }

    printf("Sequencia = [");
    for(j = 0; j < n; j++){
        if(j == n - 1){
            printf("%d]\n", vet_seq[j]);
        }else{
            printf("%d, ", vet_seq[j]);
        }
    }
    if(aux){
        printf("Existem i = %d e m = %d.", i - 1, n_seq - 1);
    }else{
        printf("Nao Existem i e m.");
    }

    return 0;
}
