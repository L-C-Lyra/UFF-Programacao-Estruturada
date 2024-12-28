#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT.c"

int main(){
    char * exp_1 = "{a*[(a+b)*c]+g-[(q+e)/(f*b)]}";
    char * exp_2 = "{a+(b-(c*d)/p]+k)-m}";
    char * exp_3 = "{m+n)*[v/p]+k*u(p-m}";
    char * exp_4 = "(({o*p}*[r+k]+a*u[r/e])";

    printf("Expressao 1 = %s\n", exp_1);
    if(is_balanced_exp(exp_1, strlen(exp_1))){
        printf("Expressao 1 EH BALANCEADA.\n");
    }else{
        printf("Expressao 1 EH DESBALANCEADA.\n");
    }

    printf("\nExpressao 2 = %s\n", exp_2);
    if(is_balanced_exp(exp_2, strlen(exp_2))){
        printf("Expressao 2 EH BALANCEADA.\n");
    }else{
        printf("Expressao 2 EH DESBALANCEADA.\n");
    }

    printf("\nExpressao 3 = %s\n", exp_3);
    if(is_balanced_exp(exp_3, strlen(exp_3))){
        printf("Expressao 3 EH BALANCEADA.\n");
    }else{
        printf("Expressao 3 EH DESBALANCEADA.\n");
    }

    printf("\nExpressao 4 = %s\n", exp_4);
    if(is_balanced_exp(exp_4, strlen(exp_4))){
        printf("Expressao 4 EH BALANCEADA.");
    }else{
        printf("Expressao 4 EH DESBALANCEADA.");
    }

    return 0;
}
