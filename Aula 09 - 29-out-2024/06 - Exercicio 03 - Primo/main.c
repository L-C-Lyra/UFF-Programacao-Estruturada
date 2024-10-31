#include <stdio.h>
#include <stdlib.h>

int primo(int n, int div){
    if(n == 1){
        return 0;
    }else if(div == n){
        return 1;
    }

    return((n % div != 0) && primo(n, div + 1));
}

int main(){
    int n;

    printf("n: ");
    scanf("%d", &n);

    if(primo(n, 2)){
        printf("%d EH um Numero Primo.", n);
    }else{
        printf("%d NAO EH um Numero Primo.", n);
    }

    return 0;
}
