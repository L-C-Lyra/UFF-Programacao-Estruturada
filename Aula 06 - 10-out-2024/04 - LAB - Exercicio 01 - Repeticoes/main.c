#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j;
    int cont = 0;

    printf("n: ");
    scanf("%d", &n);

    int vet_seq[n];

    for(i = 0; i < n; i++){
        printf("Seq[%d] = ", i);
        scanf("%d", &vet_seq[i]);
    }

    for(i = 0; i < n; i++){
        if(vet_seq[i] >= 0){
            int aux = vet_seq[i];

            for(j = i; j < n; j++){
                if(aux == vet_seq[j]){
                    cont++;
                    if(vet_seq[j] > 0){
                        vet_seq[j] *= -1;
                    }else{
                        vet_seq[j] = -1;
                    }
                }
            }

            printf("\nO Numero %d aparece %d vez(es) na Sequencia.", aux, cont);
            cont = 0;
        }
    }

    return 0;
}
