#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ADT.c"

int menu(){
    int opt;

    printf("-------- Menu -------\n");
    printf(" 1. Imprimir\n");
    printf(" 2. Inserir\n");
    printf(" 3. Adicionar\n");
    printf(" 4. Remover\n");
    printf(" 5. Busca Inteligente\n");
    printf(" 6. Inverter\n");
    printf(" 7. Rotacionar\n");
    printf(" 8. Ordenar\n");
    printf(" 9. Duplicatas\n");
    printf("10. Soma Par\n");
    printf("15. Sair\n");
    printf("---------------------\n");
    printf("Opcao: ");
     scanf("%d", &opt);

    return opt;
}

int main(){
    int opt;
    tVector * vet_v = vetalloc(10);

    vet_v -> vet[0] = 11;   vet_v -> vet[1] = 5;    vet_v -> vet[2] = 7;    vet_v -> vet[3] = 15;
    vet_v -> vet[4] = 9;    vet_v -> vet[5] = 87;   vet_v -> vet[6] = 10;   vet_v -> vet[7] = 8;
    vet_v -> size = 8;

    opt = menu();
    while(opt != 15){
        switch(opt){
            case 1:
                vetprint(vet_v);
                break;

            case 2:
                vetinsert(vet_v);
                break;

            case 3:
                vetadd(vet_v);
                break;

            case 4:
                vetremove(vet_v);
                break;

            case 5:
                smart_search(vet_v);
                break;

            case 6:
                vetreverse(vet_v);
                break;

            case 7:
                rotate_left(vet_v);
                break;

            case 8:
                vetsort(vet_v);
                break;

            case 9:
                duplicates(vet_v);
                break;

            case 10:
                even_sum(vet_v);
                break;

            default:
                printf("Opcao Invalida.\n");
        }
        opt = menu();
    }

    printf("Fim.");

    vetfree(vet_v);
    return 0;
}
