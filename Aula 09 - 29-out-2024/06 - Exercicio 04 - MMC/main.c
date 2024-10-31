#include <stdio.h>
#include <stdlib.h>

int mmc(int m, int n, int divd){
    if((divd % m == 0) && (divd % n == 0)){
        return divd;
    }else{
        mmc(m, n, divd + 1);
    }
}

int main(){
    int m, n;

    printf("m: ");
    scanf("%d", &m);

    printf("n: ");
    scanf("%d", &n);

    printf("MMC(%d, %d) = %d", m, n, mmc(m, n, 1));

    return 0;
}
