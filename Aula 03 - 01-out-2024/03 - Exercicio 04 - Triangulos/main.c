#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, cat_a, cat_b, hypotenuse, aux;

    printf("Digite o Comprimento Maximo da Hipotenusa: ");
    scanf("%d", &n);

    for(hypotenuse = 1; hypotenuse <= n; hypotenuse++){
        aux = 0;

        for(cat_a = 1; (cat_a < hypotenuse) && (!aux); cat_a++){
            cat_b = cat_a;

            while((cat_a * cat_a) + (cat_b * cat_b) < (hypotenuse * hypotenuse)){
                cat_b++;
            }
            if((cat_a * cat_a) + (cat_b * cat_b) == (hypotenuse * hypotenuse)){
                printf("Hipotenusa = %d; Catetos = %d & %d\n", hypotenuse, cat_a, cat_b);
                aux = 1;
            }
        }
    }

    return 0;
}
