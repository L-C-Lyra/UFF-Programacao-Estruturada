#include <stdio.h>
#include <stdlib.h>

int fat(int f){
    int i;
    int fact = 1;

    for(i = 1; i <= f; i++){
        fact *= i;
    }

    return fact;
}

float series(int n){
    int i;
    float s = 1;

    for(i = 1; i <= n; i++){
        s += (1.0 / fat(i));
    }

    return s;
}

int main(){
    int n;

    do{
        printf("n: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("S(%d) = %.2f", n, series(n));

    return 0;
}
