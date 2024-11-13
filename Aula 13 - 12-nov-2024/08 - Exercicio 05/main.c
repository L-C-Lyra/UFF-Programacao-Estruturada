#include <stdio.h>
#include <stdlib.h>

void montyphyton(int n, int mp, int i){
    if(i == mp){
        return;
    }else{
        if(i == mp - 1){
            printf("%d.", n);
        }else{
            printf("%d, ", n);
        }

        if(n % 5 == 0){
            n -= 4;
        }else{
            n += 3;
        }
    }

    montyphyton(n, mp, i + 1);
}

int main(){
    int n, mp;

    printf("n: ");
    scanf("%d", &n);

    printf("mp: ");
    scanf("%d", &mp);

    montyphyton(n, mp, 0);

    return 0;
}
