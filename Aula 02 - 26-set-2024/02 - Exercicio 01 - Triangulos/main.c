#include <stdio.h>
#include <stdlib.h>

int main(){
    int sideA, sideB, sideC;

    scanf("%d%d%d", &sideA, &sideB, &sideC);

    if((sideA == sideB) && (sideB == sideC)){
        printf("Triangulo Equilatero.");
    }else if((sideA == sideB) || (sideA == sideC) || (sideB == sideC)){
        printf("Triangulo Isosceles.");
    }else{
        printf("Triangulo Escaleno.");
    }

    return 0;
}
