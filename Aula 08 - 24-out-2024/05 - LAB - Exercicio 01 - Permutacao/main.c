#include <stdio.h>
#include <stdlib.h>

int contadigitos(int n, int d){
    int n_d;
    int conta_d = 0;

    while(n != 0){
        n_d = n % 10;
        n /= 10;
        if(n_d == d){
            conta_d++;
        }
    }

    return conta_d;
}

int main(){
    int n_1, n_2, d, perm = 0;

    printf("Digite dois Inteiros: ");
    scanf("%d%d", &n_1, &n_2);

    perm = 1;
    for(d = 1; d <= 9; d++){
        if(contadigitos(n_1, d) != contadigitos(n_2, d)){
            perm = 0;
            break;
        }
    }

    if(perm){
        printf("%d EH Permutacao de %d.", n_1, n_2);
    }else{
        printf("%d NAO EH Permutacao de %d.", n_1, n_2);
    }

    return 0;
}
