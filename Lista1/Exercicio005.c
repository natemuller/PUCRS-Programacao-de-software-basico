/*
Exercicio005.c
Feito por Natan de Aragão Müller no dia 08/08/2025 às 16h20

Enunciado: Dados trˆes valores X, Y e Z, verifique se eles podem ser os comprimentos dos lados de um tri ˆangulo, e, se forem,
verifique se  ́e um tri ˆangulo equil  ́atero (“EQUILATERO”), is  ́osceles (“ISOSCELES”) ou escaleno (“ESCALENO”).
Se eles n  ̃ao formarem um tri ˆangulo, escreva a mensagem “NAO EH TRIANGULO
*/

#include <stdio.h>

int main () {

    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);

    if(x >= y + z || y >= x + z || z >= x + y) {
        printf("NAO EH TRIANGULO");
    }

    else if (x == y && y == z) {
        printf("EQUILATERO");
    }

    else if (x != y && y != z && x != z) {
        printf("ESCALENO");
    }

    else {
        printf("ISOSCELES");
    }

    return 0;
}