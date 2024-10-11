#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n, i, lowest;
    int j = 0;

    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    if(m < n){
        lowest = m;
    }else{
        lowest = n;
    }

    int vet_m[m];
    int vet_n[n];
    int vet_mn[m + n];

    for(i = 0; i < m; i++){
        printf("A[%d] = ", i);
        scanf("%d", &vet_m[i]);
    }

    for(i = 0; i < n; i++){
        printf("B[%d] = ", i);
        scanf("%d", &vet_n[i]);
    }

    for(i = 0; i < lowest; i++){
        vet_mn[j++] = vet_m[i];
        vet_mn[j++] = vet_n[i];
    }
    if(lowest == m){
        for(i = lowest; i < m + n; i++){
            vet_mn[j++] = vet_n[i];
        }
    }else{
        for(i = lowest; i < m + n; i++){
            vet_mn[j++] = vet_m[i];
        }
    }

    for(i = 0; i < m + n; i++){
        printf("\nC[%d] = %d", i, vet_mn[i]);
    }

    return 0;
}
