#include <stdio.h>
#include <stdlib.h>

int main(){
    int side_a, side_b, side_c;

    printf("Digite os 3 Lados do Triangulo: \n");
    scanf("%d%d%d", &side_a, &side_b, &side_c);

    if((side_a == side_b) && (side_b == side_c)){
        printf("Triangulo Equilatero.");
    }else if((side_a == side_b) || (side_a == side_c) || (side_b == side_c)){
        printf("Triangulo Isosceles.");
    }else{
        printf("Triangulo Escaleno.");
    }

    return 0;
}
