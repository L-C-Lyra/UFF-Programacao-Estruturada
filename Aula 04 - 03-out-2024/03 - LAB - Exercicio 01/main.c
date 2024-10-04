#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j, adding, adder, aux = 0;

    printf("n: ");
    scanf("%d", &n);

    for(i = 2; i < n / 2; i++){
        adding = i;
        adder = n - i;

        int dividers = 0;
        for(j = 2; j < adding; j++){
            if(adding % j == 0){
                dividers++;
                break;
            }
        }
        if(dividers == 0){
            for(j = 2; j < adder; j++){
                if(adder % j == 0){
                    dividers++;
                    break;
                }
            }
            if(dividers == 0){
                printf("%d pode ser Expresso pela Soma %d + %d.\n", n, adding, adder);
                aux = 1;
            }
        }
    }
    if(aux == 0){
        printf("%d nao pode ser Expresso pela Soma de 2 Numeros Primos.\n", n);
    }

    return 0;
}
