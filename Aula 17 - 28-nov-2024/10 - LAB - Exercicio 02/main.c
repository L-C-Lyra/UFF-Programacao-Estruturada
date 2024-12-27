#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 10;
    int i;
    int * vet_v = (int *) malloc(n * sizeof(int));

    vet_v[0] = 8;   vet_v[1] = 23;  vet_v[2] = 28;  vet_v[3] = 47;  vet_v[4] = 58;
    vet_v[5] = 69;  vet_v[6] = 72;  vet_v[7] = 83;  vet_v[8] = 90;  vet_v[9] = 94;

    printf("Vetor V[%d]: [", n);
    for(i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d]\n", vet_v[i]);
        }else{
            printf("%d, ", vet_v[i]);
        }
    }

    int opt;
    printf("Deseja alterar alguma posicao? (0 - NAO / 1 - SIM) ");
    scanf("%d", &opt);

    while(opt){
        int pos, elem;

        printf("Posicao: ");
        scanf("%d", &pos);

        printf("Elemento: ");
        scanf("%d", &elem);

        if(elem > vet_v[pos]){
            vet_v[pos] = elem;

            while((pos < n - 1) && (vet_v[pos] > vet_v[pos + 1])){
                int temp;

                temp = vet_v[pos];
                vet_v[pos] = vet_v[pos + 1];
                vet_v[pos + 1] = temp;

                pos++;
            }
        }else{
            vet_v[pos] = elem;

            while((pos > 0) && (vet_v[pos] < vet_v[pos - 1])){
                int temp;

                temp = vet_v[pos];
                vet_v[pos] = vet_v[pos - 1];
                vet_v[pos - 1] = temp;

                pos--;
            }
        }

        printf("Vetor V[%d]: [", n);
        for(i = 0; i < n; i++){
            if(i == n - 1){
                printf("%d]\n", vet_v[i]);
            }else{
                printf("%d, ", vet_v[i]);
            }
        }

        printf("Deseja alterar alguma posicao? (0 - NAO / 1 - SIM) ");
        scanf("%d", &opt);
    }

    free(vet_v);
    return 0;
}
