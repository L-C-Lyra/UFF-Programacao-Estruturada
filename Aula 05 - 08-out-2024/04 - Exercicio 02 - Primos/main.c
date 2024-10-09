#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i, j;
    int div = 0;
    int p = 0;

    printf("n: ");
    scanf("%d", &n);

    int vet_p[n];

    for(i = 2; i <= n; i++){
        for(j = 1; j <= i; j++){
            if(i % j == 0){
                div++;
            }
        }
        if(div == 2){
            vet_p[p] = i;
            p++;
        }

        div = 0;
    }

    for(i = 0; i < p; i++){
        if(i < p - 1){
            printf("%d - ", vet_p[i]);
        }else{
            printf("%d.", vet_p[i]);
        }
    }

    return 0;
}
