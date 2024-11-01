#include <stdio.h>
#include <stdlib.h>

int sum_digits(int n){
    if(n == 0){
        return 0;
    }

    return((n % 10) + sum_digits(n / 10));
}

int main(){
    int n, sum_n;

    printf("n: ");
    scanf("%d", &n);

    sum_n = sum_digits(n);

    printf("Soma dos Digitos de %d = %d", n, sum_n);

    return 0;
}
