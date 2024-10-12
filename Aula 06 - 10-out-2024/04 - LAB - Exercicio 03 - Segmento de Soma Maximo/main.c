#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, n_max, i, j, k, sum_seq, max_seq;

    printf("n: ");
    scanf("%d", &n);

    int vet_seq[n];
    int seq_max[n];

    for(i = 0; i < n; i++){
        printf("Seq[%d] = ", i);
        scanf("%d", &vet_seq[i]);
    }
    printf("\n");

    max_seq = vet_seq[0];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            sum_seq = 0;

            for(k = i; k <= j; k++){
                sum_seq += vet_seq[k];
            }
            if(sum_seq > max_seq){
                max_seq = sum_seq;

                n_max = 0;
                for(k = i; k <= j; k++){
                    seq_max[n_max] = vet_seq[k];
                    n_max++;
                }
            }
        }
    }

    printf("Sequencia = [");
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet_seq[i]);
        }else{
            printf("%d, ", vet_seq[i]);
        }
    }

    printf("Sequencia Maxima = [");
    for(i = 0; i < n_max; i++){
        if(i == n_max - 1){
            printf("%d]\n", seq_max[i]);
        }else{
            printf("%d, ", seq_max[i]);
        }
    }

    printf("Soma Maxima = %d", max_seq);

    return 0;
}
