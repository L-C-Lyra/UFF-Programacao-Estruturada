#include <stdio.h>
#include <stdlib.h>

void granizo(int n){
    if(n == 1){
        printf("%d.", n);
    }else{
        printf("%d, ", n);

        if(n % 2 == 0){
            n /= 2;
        }else{
            n = (3 * n) + 1;
        }

        granizo(n);
    }
}

int conta_granizo(int n){
    if(n == 1){
        return 1;
    }else{
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = (3 * n) + 1;
        }

        return(1 + conta_granizo(n));
    }
}

int main(){
    int n;

    printf("n: ");
    scanf("%d", &n);

    granizo(n);

    printf("\nTamanho = %d", conta_granizo(n));

    return 0;
}
