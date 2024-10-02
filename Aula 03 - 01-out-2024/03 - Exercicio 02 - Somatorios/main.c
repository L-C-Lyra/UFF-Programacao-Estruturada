#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, m;
    int sum_even = 0, sum_three = 0, cont_three = 0, avg_three = 0;

    printf("n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Numero %d: ", i + 1);
        scanf("%d", &m);

        if(m % 2 == 0){
            sum_even += m;
        }
        if(m % 3 == 0){
            sum_three += m;
            cont_three++;
        }
    }

    if(cont_three != 0){
        avg_three = sum_three / cont_three;
    }

    printf("Soma dos Pares: %d\n", sum_even);
    printf("Media dos Multiplos de 3: %d\n", avg_three);

    return 0;
}
