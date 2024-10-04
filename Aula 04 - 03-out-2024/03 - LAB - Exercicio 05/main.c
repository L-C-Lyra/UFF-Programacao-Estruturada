#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, m, parity, k, k_size, k_alter;

    printf("n: ");
    scanf("%d", &n);

    printf("Entre com o 1o Elemento da Sequencia: ");
    scanf("%d", &m);

    parity = m % 2;
    k = 1;
    i = 1;
    while((i < n) && (m % 2 == parity)){
        printf("Entre com o %do Elemento da Sequencia: ", i + 1);
        scanf("%d", &m);

        i++;

        if(m % 2 == parity){
            k++;
        }
    }

    k_alter = 1;
    while(i < n){
        parity = (parity + 1) % 2;

        k_size = 1;
        while((i < n) && (m % 2 == parity)){
            printf("Entre com o %do Elemento da Sequencia: ", i + 1);
            scanf("%d", &m);

            i++;

            if(m % 2 == parity){
                k_size++;
            }
        }
        if(k_size != k){
            k_alter = 0;
            break;
        }
    }

    if((m % 2 != parity) && (k != 1)){
        k_alter = 0;
    }

    if(k_alter){
        printf("A Sequencia eh %d-intercalada.", k);
    }else{
        printf("A Sequencia nao eh k-intercalada.");
    }

    return 0;
}
