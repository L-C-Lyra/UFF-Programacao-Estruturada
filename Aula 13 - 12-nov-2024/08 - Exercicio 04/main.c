#include <stdio.h>
#include <stdlib.h>

int positives(int n, int * vet_v1, int * vet_v2, int i_1, int i_2){
    if(i_1 == n){
        return i_2;
    }

    if(vet_v1[i_1] >= 0){
        vet_v2[i_2] = vet_v1[i_1];

        return positives(n, vet_v1, vet_v2, i_1 + 1, i_2 + 1);
    }else{
        return positives(n, vet_v1, vet_v2, i_1 + 1, i_2);
    }
}

int main(){
    int n, pos_n, i;
    int * vet_v1;
    int * vet_v2;

    printf("n: ");
    scanf("%d", &n);

    vet_v1 = (int *) malloc(n * sizeof(int));
    vet_v2 = (int *) malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        printf("V1[%d] = ", i);
        scanf("%d", &vet_v1[i]);
    }
    printf("\n");

    pos_n = positives(n, vet_v1, vet_v2, 0, 0);

    for(i = 0; i < pos_n; i++){
        printf("V1+[%d] = %d", i, vet_v2[i]);
        if(!(i == pos_n - 1)){
            printf("\n");
        }
    }

    return 0;
}
