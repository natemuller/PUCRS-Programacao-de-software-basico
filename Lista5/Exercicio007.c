/*
Exercicio007.c, por Natan de Aragão Müller na data de 25/09/2025 - 14h01.

Enunciado: screva um programa em C que leia dois n  ́umeros inteiros decimais sem sinal. O primeiro n  ́umero corresponde a
um valor inteiro que ocupa no m  ́aximo 32 bits na mem  ́oria. E o segundo n  ́umero ser  ́a sempre um valor de 0 at ́e 31,
que corresponde ao n  ́umero do bit cujo valor se deseja obter e mostrar. Por exemplo, caso o primeiro n  ́umero lido
seja 2 (armazenado na mem  ́oria em bin  ́ario como 00000000 00000000 00000000 00000010), e o segundo
n  ́umero seja 0, o resultado dever  ́a ser 0, pois o bit menos significativo  ́e 0. Por outro lado, se primeiro n  ́umero lido
for 2 e o segundo n  ́umero for 1, o resultado dever  ́a ser  ́a 1, pois o segundo bit menos significativo  ́e 1.
*/

#include <stdio.h>

int main() {
    unsigned int num;
    int pos;
    scanf("%u %d", &num, &pos);

    unsigned int bit = (num >> pos) & 1;
    printf("%u\n", bit);

    return 0;
}
