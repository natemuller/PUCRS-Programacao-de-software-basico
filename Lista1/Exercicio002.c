/*
Exercicio002.c
Feito por Natan de Aragão Müller no dia 07/08/2025 às 19h46

Enunciado: Escreva um programa que lê uma temperatura em graus Fahrenheit (como um valor real) e faz a convers  ̃ao de
temperaturas de Fahrenheit para Celsius, imprimindo a temperatura em graus Celsius.
*/

#include <stdio.h>

int main () {

    double fahrenheit;

    scanf("%lf", &fahrenheit);

    double celsius = ((5.0/9.0) * (fahrenheit - 32.0));

    printf("%.4f", celsius);

    return 0;
}