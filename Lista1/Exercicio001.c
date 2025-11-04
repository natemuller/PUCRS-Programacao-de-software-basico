/*
Exercicio001.c
Feito por Natan de Aragão Müller no dia 08/08/2025 às 16h04
Após a correção, refeito no dia 18/08/2025 às 23h59

Enunciado: Faça um programa para resolver equações do 2° grau. Leia os coeficientes a, b e c da equaçãoo do segundo grau
ax2+ bx + c, com a ̸= 0, e imprima o número de raízes reais e cada uma das raízes reais.
*/

#include <stdio.h>
#include <math.h>

int main () {

    double a, b, c;
    int numRaizes; //Apenas alterei e declarei como int a variável numRaizes
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = ((b * b) - (4.0 * a * c));

    if (delta > 0) {
        double r1, r2;
        numRaizes = 2;
        r1 = (((b * -1) + (sqrt(delta))) / (2 * a));
        r2 = (((b * -1) - (sqrt(delta))) / (2 * a));

        printf("%d %.4f %.4f", numRaizes, r1, r2);
    }

    else if (delta == 0) {
        double r;
        numRaizes = 1;
        r = (((b * -1) + (sqrt(delta))) / (2 * a));

        printf("%d %.4f", numRaizes, r);
    }

    else {
        numRaizes = 0;
        printf("%d", numRaizes);
    }

    return 0;
}