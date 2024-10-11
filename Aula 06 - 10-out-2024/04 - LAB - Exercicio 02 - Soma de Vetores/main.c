#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, digit_sum;
    int carry_over = 0;

    printf("n: ");
    scanf("%d", &n);

    int vet_a[n + 1];
    int vet_b[n + 1];
    int vet_sum[n + 1];

    for(i = 1; i <= n; i++){
        printf("A[%d] = ", i);
        scanf("%d", &vet_a[i]);
    }
    vet_a[0] = 0;

    for(i = 1; i <= n; i++){
        printf("B[%d] = ", i);
        scanf("%d", &vet_b[i]);
    }
    vet_b[0] = 0;

    for(i = n; i >= 1; i--){
        digit_sum = vet_a[i] + vet_b[i] + carry_over;
        vet_sum[i] = digit_sum % 10;
        carry_over = digit_sum / 10;
    }
    vet_sum[0] = carry_over;

    printf("\n   A: ");
    if(vet_a[0] == 0){
        printf(" ");

        for(i = 1; i <= n; i++){
            printf("%d", vet_a[i]);
        }
    }else{
        for(i = 0; i <= n; i++){
            printf("%d", vet_a[i]);
        }
    }

    printf("\n   B: ");
    if(vet_b[0] == 0){
        printf(" ");

        for(i = 1; i <= n; i++){
            printf("%d", vet_b[i]);
        }
    }else{
        for(i = 0; i <= n; i++){
            printf("%d", vet_b[i]);
        }
    }

    printf("\n");
    for(i = 0; i <= n + 6; i++){
        printf("-");
    }

    printf("\nSoma: ");
    if(vet_sum[0] == 0){
        printf(" ");

        for(i = 1; i <= n; i++){
            printf("%d", vet_sum[i]);
        }
    }else{
        for(i = 0; i <= n; i++){
            printf("%d", vet_sum[i]);
        }
    }

    return 0;
}
