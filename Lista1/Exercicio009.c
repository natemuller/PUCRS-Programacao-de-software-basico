/*
Exercicio009.c
Feito por Natan de Aragão Müller no dia 10/08/2025 às 23h26

Enunciado: Fac ̧a um programa que leia um n  ́umero N que indica quantos valores inteiros e positivos devem ser lidos a seguir.
Para cada n  ́umero lido, mostre o valor lido e o fatorial desse valor
*/

#include <stdio.h>

int calculaFatorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    else {
        return (num * calculaFatorial(num - 1));
    }
}

int main() {

    int tam;
    scanf("%d", &tam);

    int vet[tam];
    for(int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < tam; i++) {
        int num = vet[i];
        int fat = calculaFatorial(num);
        printf("%d %d\n", num, fat);
    }

    return 0;
}