#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x, i;
    int x_odd = 1;
    float s = 0.0;

    printf("x: ");
    scanf("%d", &x);

    for(i = 1; i <= 50; i++){
        s += (1.0 * pow(2, i)) / (x_odd * (pow(x, (i + 3))));
        x_odd += 2;
    }

    printf("s: %f", s);

    return 0;
}
