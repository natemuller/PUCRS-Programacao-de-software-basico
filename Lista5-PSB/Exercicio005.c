/*
Exercicio005.c, por Natan de Aragão Müller na data de 25/09/2025 - 13h52.

Enunciado: Em alguns dos primeiros microcomputadores pessoais, que usavam processadores de 8 bits, alguns programas
(principalmente jogos) redefiniam os caracteres de texto usando um padr  ̃ao de 8 por 8 pixels para cada caractere.
Assim, para cada caractere eram definidos 8 bytes que constituiam o padr  ̃ao de pontos usado para desenhar esse
caractere. Basicamente o valor de cada byte deve ser convertido para bin  ́ario e, se o bit estivesse ligado, um ponto
era pintado; se o bit estivesse desligado, o ponto n  ̃ao era pintado.
Por exemplo, um caractere definido como 112 (em bin  ́ario 01110000), 56 (em bin  ́ario 00111000), 56 (em bin  ́ario
00111000), 108 (em bin  ́ario 01101100), 124 (em bin  ́ario 01111100), 198 (em bin  ́ario 11000110), 238 (em bin  ́ario
11101110) e 0 (em bin  ́ario 00000000), ...
*/

#include <stdio.h>

int main() {
    int linha[8];

    for (int i = 0; i < 8; i++) {
        scanf("%d", &linha[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            if (linha[i] & (1 << bit))
                printf("X");
            else
                printf(".");
        }
        printf("\n");
    }

    return 0;
}
