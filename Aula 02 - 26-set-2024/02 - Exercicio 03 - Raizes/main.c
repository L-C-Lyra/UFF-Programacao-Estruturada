#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float a, b, c, r1, r2, d;

    prinf("Digite os Valores das Variaveis a, b, c: \n");
    scanf("%f%f%f", &a, &b, &c);

    d = (b * b) - (4 * a * c);
    switch(d > 0){
        case 1:
            r1 = (-b + sqrt(d)) / (2 * a);
            r2 = (-b - sqrt(d)) / (2 * a);
            printf("r1 = %.2f\n", r1);
            printf("r2 = %.2f", r2);
            break;

        case 0:
            switch(d < 0){
                case 1:
                    printf("Nao existe RAIZES REAIS.");
                    break;

                case 0:
                    r1 = r2 = (-b) / (2 * a);
                    printf("r1 = r2 = %.2f", r1);
                    break;
            }
    }

    return 0;
}
