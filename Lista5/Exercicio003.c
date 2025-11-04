/*
Exercicio003.c, por Natan de Aragão Müller na data de 25/09/2025 - 13h42.

Enunciado: Escreva um programa que leia as intensidades de verde, vermelho e azul (todos como valores de 0 at ́e 255) e gere
o valor correspondente na paleta fixa de 256 cores para esse tipo de sistema.
*/

#include <stdio.h>

int main() {
    int verde, vermelho, azul;
    scanf("%d %d %d", &verde, &vermelho, &azul);

    int g = verde >> 5;      
    int r = vermelho >> 5;   
    int b = azul >> 6;       

    int resultado = (g << 5) | (r << 2) | b;

    printf("%d\n", resultado);

    return 0;
}
