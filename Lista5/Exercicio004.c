/*
Exercicio004.c, por Natan de Aragão Müller na data de 25/09/2025 - 13h45.

Enunciado: Escreva um programa que leia o valor correspondente na paleta fixa de 256 cores para esse tipo de sistema e mostre
as suas intensidades de verde, vermelho e azul.
*/

#include <stdio.h>

int main() {
    int valor;
    scanf("%d", &valor);

    int g = (valor >> 5) & 0x07;  
    int r = (valor >> 2) & 0x07; 
    int b = valor & 0x03;         

    g = g << 5; 
    r = r << 5; 
    b = b << 6; 

    printf("%d %d %d\n", g, r, b);

    return 0;
}
