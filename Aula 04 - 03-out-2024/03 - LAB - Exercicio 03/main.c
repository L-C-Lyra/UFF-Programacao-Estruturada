#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, rev_n, rev_sum = 0;

    printf("n: ");
    scanf("%d", &n);

    for(i = n; n != 0; n /= 10){
        rev_n = n % 10;
        rev_sum = (rev_sum * 10) + rev_n;
    }
    printf("O Numero Reverso eh: %d.\n", rev_sum);

    return 0;
}
