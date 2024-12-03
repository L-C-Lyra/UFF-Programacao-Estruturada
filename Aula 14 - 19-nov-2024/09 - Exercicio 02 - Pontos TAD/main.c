#include <stdio.h>
#include <stdlib.h>
#include "ADT.c"

int main(){
    tPoint * p = pointalloc(2.0, 1.0);
    tPoint * q = pointalloc(3.4, 2.1);

    pointprint(p);
    pointprint(q);

    float d_pq;

    d_pq = distance(p, q);
    printf("d(p,q) = %f", d_pq);

    pointfree(p);
    pointfree(q);
    return 0;
}
