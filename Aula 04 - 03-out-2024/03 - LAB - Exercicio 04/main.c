#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, div, prime_div;

    printf("n: ");
    scanf("%d", &n);

    div = 2;
    while(n > 1){
        if(n % div == 0){
            prime_div = 1;

            for(i = 2; i <= div - 1; i++){
                if(div % i == 0){
                    prime_div = 0;
                    break;
                }
            }
            if(prime_div == 1){
                printf("%d\n", div);
                n /= div;
            }
            else{
                div++;
            }
        }
        else{
            div++;
        }
    }

    return 0;
}
