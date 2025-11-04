/*  
Exercicio003.c

Feito por Natan de Aragão Müller no dia 27/08/2025 às 18h05.

Enunciado: Considere uma linha no formato CSV (Comma-Separated Values) que use como separador o caractere ’;’ (ponto-e-
v ́ırgula) e que contenha as seguintes informac ̧  ̃oes sobre uma pessoa (exatamente na seguinte ordem): nome (at ́e
40 caracteres  ́uteis), idade (expressa como um valor inteiro), peso (em kg, expresso como um n  ́umero real, usando
ponto como separador de casas decimais) e altura (em metros, expressa como um n  ́umero real, usando ponto como
separador de casas decimais). Escreva um programa em C que leia uma linha nesse formato CSV, calculando o
IMC ( ́Indice de Massa Corporal) dessa Pessoa.
*/

#include <stdio.h>

double calculaIMC(double peso, double altura) {
    double imc = ((peso)/(altura * altura));
    return imc;
}
int main () {

    int idade;
    double altura, peso;
    char nome[30];
    scanf("%29[^;]; %d; %lf; %lf", nome, &idade, &peso, &altura);

    for(int i = 0; nome[i] != '\0'; i++) {
        printf("%c", nome[i]);
    }

    printf(": %.4f", calculaIMC(peso, altura));

    return 0;
}