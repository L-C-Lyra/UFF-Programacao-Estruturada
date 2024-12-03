#include <stdio.h>
#include <stdlib.h>

struct item{
    char * name;
    int qty;
    float price;
    float total;
};

void itemread(struct item * it){
    printf("Nome do Produto: ");
    scanf("%s", it -> name);

    printf("Preco do Produto: ");
    scanf("%f", &it -> price);

    printf("Quantidade do Produto: ");
    scanf("%d", &it -> qty);

    it -> total = (float) (it -> qty) * (it -> price);
}

void itemprint(struct item * it){
    printf("Nome: %s\n", it -> name);
    printf("Preco: R$%.2f\n", it -> price);
    printf("Quantidade: %d\n", it -> qty);
    printf("Total: R$%.2f", it -> total);
}

int main(){
    struct item it;
    struct item * pointer_it;

    pointer_it = &it;
    pointer_it -> name = (char *) malloc(50 * sizeof(char));

    itemread(pointer_it);

    itemprint(pointer_it);

    free(pointer_it -> name);
    return 0;
}
