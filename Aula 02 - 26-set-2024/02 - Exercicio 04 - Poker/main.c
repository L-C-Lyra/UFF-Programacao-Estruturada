#include <stdio.h>
#include <stdlib.h>

int main(){
    int card_a, card_b, card_c;

    printf("Digite as Cartas: \n");
    scanf("%d%d%d", &card_a, &card_b, &card_c);

    if((card_a == card_b) && (card_b == card_c)){
        printf("Three of a Kind!");
    }else if(((card_a == card_b + 1) && (card_a == card_c + 2)) || ((card_a == card_c + 1) && (card_a == card_b + 2)) ||
             ((card_b == card_a + 1) && (card_b == card_c + 2)) || ((card_b == card_c + 1) && (card_b == card_a + 2)) ||
             ((card_c == card_a + 1) && (card_c == card_b + 2)) || ((card_c == card_b + 1) && (card_c == card_a + 2))){
                printf("Sequence!");
             }else if((card_a == card_b) || (card_a == card_c) || (card_b == card_c)){
                printf("One Pair!");
             }else{
                printf("Eh... Lascou.");
             }

    return 0;
}
