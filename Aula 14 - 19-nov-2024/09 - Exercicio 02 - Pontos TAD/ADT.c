#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct typePoint{
    float x;
    float y;
}tPoint;

tPoint * pointalloc(float x, float y){
    tPoint * p = malloc(sizeof(tPoint));
    if(p == NULL){
        printf("Memoria Insuficiente!");
        exit(1);
    }

    p -> x = x;
    p -> y = y;

    return p;
}

void pointprint(tPoint * p){
    if (p == NULL) {
        printf("Erro: Ponto Nulo!\n");
        exit(1);
    }

    printf("x = %f\n", p -> x);
    printf("y = %f\n", p -> y);
}

void pointfree(tPoint * p){
    free(p);
}

float distance(tPoint * p_1, tPoint * p_2){
    if (p_1 == NULL || p_2 == NULL){
        printf("Erro: Ponto Nulo!\n");
        return -1;
    }

    float d_x, d_y;

    d_x = ((p_1 -> x) - (p_2 -> x)) * ((p_1 -> x) - (p_2 -> x));
    d_y = ((p_1 -> y) - (p_2 -> y)) * ((p_1 -> y) - (p_2 -> y));

    return sqrt(d_x + d_y);
}
