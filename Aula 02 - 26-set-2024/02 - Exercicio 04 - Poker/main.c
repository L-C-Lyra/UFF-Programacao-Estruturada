#include <stdio.h>
#include <stdlib.h>

int main(){
    int card1, card2, card3;

    scanf("%d%d%d", &card1, &card2, &card3);

    if((card1 == card2) && (card2 == card3)){
        printf("Three of a Kind!");
    }else if(((card1 == card2 + 1) && (card1 == card3 + 2)) || ((card1 == card3 + 1) && (card1 == card2 + 2)) ||
             ((card2 == card1 + 1) && (card2 == card3 + 2)) || ((card2 == card3 + 1) && (card2 == card1 + 2)) ||
             ((card3 == card1 + 1) && (card3 == card2 + 2)) || ((card3 == card2 + 1) && (card3 == card1 + 2))){
                printf("Sequence!");
             }else if((card1 == card2) || (card1 == card3) || (card2 == card3)){
                printf("One Pair!");
             }else{
                printf("Eh... Lascou.");
             }

    return 0;
}
