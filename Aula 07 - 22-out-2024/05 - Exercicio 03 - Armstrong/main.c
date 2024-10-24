#include <stdio.h>
#include <stdlib.h>

int armstrong(int n){
    int n_dig, i;
    int n_aux = n;
    int sum_arms = 0;

    for(i = 0; i < 3; i++){
        n_dig = n_aux % 10;
        sum_arms += n_dig * n_dig * n_dig;
        n_aux /= 10;
    }

    if(sum_arms == n){
        return 1;
    }
    return 0;
}

int main(){
    int n;

    printf("n: ");
    scanf("%d", &n);

    if(armstrong(n)){
        printf("%d EH um Numero de Armstrong.", n);
    }else{
        printf("%d NAO EH um Numero de Armstrong.", n);
    }

    return 0;
}
