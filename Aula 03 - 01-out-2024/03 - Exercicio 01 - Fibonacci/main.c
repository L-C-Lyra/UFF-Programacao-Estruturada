#include <stdio.h>
#include <stdlib.h>

int main(){
    int fib_a, fib_b, fib = 0;
    int n;

    do{
        printf("n: ");
        scanf("%d", &n);
    }while(n <= 0);

    while(fib < n){
        if(fib == 0){
            fib_a = 0;
            fib_b = 1;
            fib = fib_a + fib_b;

            printf("%d, ", fib_a);
            printf("%d, ", fib_b);
            printf("%d, ", fib);
        }
        fib_a = fib_b;
        fib_b = fib;
        fib = fib_a + fib_b;

        if((fib + fib_b) > n){
            printf("%d.", fib);
            break;
        }else{
            printf("%d, ", fib);
        }
    }

    return 0;
}
