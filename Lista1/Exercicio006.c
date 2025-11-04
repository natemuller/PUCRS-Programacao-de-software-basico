/*
Exercicio006.c
Feito por Natan de Aragão Müller no dia 10/8/2025 às 23h07

Enunciado: Escrever um programa que lˆe um valor inteiro n, maior do que 0 (zero), e que mostra todos os divisores deste
n  ́umero, desconsiderando 1 e o pr  ́oprio n  ́umero como divisores, ou um asterisco (“*”) caso o n  ́umero n  ̃ao possua
divisores.
*/

#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("*");
    }

    int temDivisor = 0;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            if (temDivisor) {
                printf(" ");
            }
            printf("%d", i);
            temDivisor = 1;
        }
    }

    if (!temDivisor) {
        printf("*");
    }

    return 0;
}