#include <stdio.h>
#include <stdlib.h>

int checa(int t1, int v1[t1], int t2, int v2[t2]){
    int i, j, aux = 0;

    for(i = 0; i < t1; i++){
        aux = 1;
        for(j = 0; j < t2; j++){
            if((i < t1) && (v1[i] == v2[j])){
                i++;
            }else{
                aux = 0;
                break;
            }
        }

        if(aux){
            return 1;
        }
    }

    return 0;
}

int main(){
    int t1, t2, i;

    printf("t1: ");
    scanf("%d", &t1);

    printf("t2: ");
    scanf("%d", &t2);

    int v1[t1];
    int v2[t2];

    for(i = 0; i < t1; i++){
        printf("v1[%d] = ", i);
        scanf("%d", &v1[i]);
    }
    printf("\n");

    for(i = 0; i < t2; i++){
        printf("v2[%d] = ", i);
        scanf("%d", &v2[i]);
    }
    printf("\n");

    if(checa(t1, v1, t2, v2)){
        printf("v2 EH uma Subsequencia de v1.");
    }else{
        printf("v2 NAO EH uma Subsequencia de v1.");
    }

    return 0;
}
