#include <stdio.h>
#include <stdlib.h>

int fib(int i){
    if(i == 0){
        return 0;
    }else if(i == 1){
        return 1;
    }

    return(fib(i - 2) + fib(i - 1));
}

int main(){
    int n, i;

    printf("n: ");
    scanf("%d", &n);

    for(i = 0; i <= n; i++){
        if(i == n){
            printf("%d.", fib(i));
        }else{
            printf("%d, ", fib(i));
        }
    }

    return 0;
}
