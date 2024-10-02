#include <stdio.h>
#include <stdlib.h>

int main(){
    int hours = 0;
    double gross_salary = 0.0;
    double tax = 0.0;
    double net_salary = 0.0;

    printf("Digite as Horas Trabalhadas: ");
    scanf("%d", &hours);

    if(hours <= 40){
        gross_salary = hours * 12;
    }else{
        gross_salary = 40 * 12;
        double extra = (hours - 40) * (12 * 1.5);
        gross_salary += extra;
    }

    if(gross_salary <= 300){
        tax = gross_salary * 0.15;
    }else if((gross_salary > 300) && (gross_salary <= 450)){
        tax = 300 * 0.15;
        tax += (gross_salary - 300) * 0.20;
    }else if(gross_salary > 450){
        tax = 300 * 0.15;
        tax += 150 * 0.20;
        tax += (gross_salary - 450) * 0.25;
    }
    net_salary = gross_salary - tax;

    printf("Salario Bruto: %.2f\n", gross_salary);
    printf("Imposto: %.2f\n", tax);
    printf("Salario Liquido: %.2f\n", net_salary);

    return 0;
}
