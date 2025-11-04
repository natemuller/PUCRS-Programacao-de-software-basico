/*
Exercicio006.c, por Natan de Aragão Müller na data de 25/09/2025 - 13h56.

Enunciado: Escreva um programa em C que leia um n  ́umero inteiro e, usando operac ̧  ̃oes bit-a-bit, conte e mostre quantos
bits est  ̃ao desligados na representac ̧  ̃ao bin  ́aria desse n  ́umero, desconsiderando os bits `a esquerda do bit 1 mais
significativo (ou seja, seu programa deve contar e mostrar quantos bits 0 h  ́a `a direita do bit 1 mais significativo).
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0 || n == -1) {
        printf("0\n");
        return 0;
    }

    unsigned int un = (unsigned int)n; 
    int msb = -1;

    for (int i = 31; i >= 0; i--) {
        if (un & (1u << i)) {
            msb = i;
            break;
        }
    }

    int zeros = 0;
    for (int i = msb - 1; i >= 0; i--) {
        if ((un & (1u << i)) == 0)
            zeros++;
    }

    printf("%d\n", zeros);
    return 0;
}
