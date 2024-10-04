#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, n, i, j, aux = 0;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    for(n = a; n <= b; n++){
        int sum_fact = 0;

        for(i = n; i != 0; i /= 10){
            int digit = i % 10;

            int fact = 1;
            for(j = 1; j <= digit; j++){
                fact *= j;
            }
            sum_fact += fact;
        }
        if(sum_fact == n){
            printf("%d\n", n);
            aux = 1;
        }
    }
    if(aux == 0){
        printf("Nao existe Numeros Poderosos neste intervalo.\n");
    }

    return 0;
}
