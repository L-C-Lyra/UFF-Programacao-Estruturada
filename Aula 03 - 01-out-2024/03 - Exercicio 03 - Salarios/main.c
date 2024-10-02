#include <stdio.h>
#include <stdlib.h>

int main(){
    int year;
    double wage;
    float pct = 0.1;

    wage = 1000;

    for(year = 1996; year <= 2024; year++){
        wage += (wage * (pct / 100));
        pct *= 2;

        printf("Salario em %d: R$ %.2lf (Percentual = %.2lf)\n", year, wage, pct);
    }

    return 0;
}
