#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    int n = 3;
    int i;
    tStack hanoi_a, hanoi_b, hanoi_c;
    stackalloc(&hanoi_a, n);
    stackalloc(&hanoi_b, n);
    stackalloc(&hanoi_c, n);

    for(i = n; i >= 1; i--){
        push(&hanoi_a, i);
    }
    han_stackprint(&hanoi_a, &hanoi_b, &hanoi_c, n);

    hanoi_towers(&hanoi_a, &hanoi_b, &hanoi_c, n);

    return 0;
}
