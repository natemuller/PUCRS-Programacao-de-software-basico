/*
Exercicio001.c, feito por Natan de Aragão Müller no dia 03/09/2025 às 09h47.
                Corrigido no dia 13/09/2025 às 02h26

Enunciado: Escreva um programa em C que, inicialmente, leia o nome de um arquivo (com no m  ́aximo 17 caracteres  ́uteis).
A seguir, seu programa dever  ́a abrir o arquivo para leitura em modo texto, lendo um n  ́umero inteiro, que cor-
responde `a quantidade de valores inteiros (que aparecem na sequˆencia dentro desse mesmo arquivo), e cada um
desses valores, calculando e mostrando o somat  ́orio desses valores. Caso o arquivo N  ̃AO exista, seu programa
deve imprimir a mensagem “ARQUIVO INEXISTENTE” (encerrando o programa com c  ́odigo de sucesso, ou seja,
0).

*/

#include <stdio.h>

int main () {

    FILE *file;
    char nome[18];
    int qtdInteiros = 0;
    long long soma = 0;  //o erro do teste 4 provavelmente foi resolvido alterando o tipo da variável para lld
    long long valor = 0;
    scanf("%17s", nome);

    file = fopen(nome, "r");
    if(file == NULL) { 
        printf("ARQUIVO INEXISTENTE\n");
        return 0;
    }

    if (fscanf(file, "%lld", &qtdInteiros) != 1) {
        fclose(file); 
        return 0; 
    }

    for (int i = 0; i < qtdInteiros; i++) { 
        if (fscanf(file, "%d", &valor) == 1) { 
            soma += valor; 
        } 
    }

    fclose(file);

    printf("%lld\n", soma);

    return 0;
}