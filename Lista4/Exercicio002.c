/*
Exercicio002.c, feito por Natan de Aragão Müller no dia 03/09/2025 às 09h57.
                Corrigido no dia 13/09/2025 às 02h29

Enunciado: Escreva um programa em C que, inicialmente, leia o nome de um arquivo (com no m  ́aximo 17 caracteres  ́uteis).
A seguir, seu programa dever  ́a abrir o arquivo para leitura em modo bin  ́ario, lendo um n  ́umero inteiro, que
corresponde `a quantidade de valores inteiros (que aparecem na sequˆencia dentro desse mesmo arquivo), e cada
um desses valores, calculando e mostrando o somat  ́orio desses valores. Caso o arquivo N  ̃AO exista, seu programa
deve imprimir a mensagem “ARQUIVO INEXISTENTE” (encerrando o programa com c  ́odigo de sucesso, ou seja,
0). Todos os valores lidos devem ser valores inteiros de 4 bytes, lidos no modo bin  ́ario

*/

#include <stdio.h>

int main () {

    FILE *file;
    char nome[18];
    int qtdInteiros = 0;
    long long soma = 0; // Alterei o tipo da variavel
    int valor = 0;
    scanf("%17s", nome);

    file = fopen(nome, "rb");  //Aqui ajustei de 'r' para 'rb'
    if(file == NULL) { 
        printf("ARQUIVO INEXISTENTE");
        return 0;
    }

    if (fread(&qtdInteiros, sizeof(int), 1, file) != 1) { 
        fclose(file); 
        return 0; 
    }

    for (int i = 0; i < qtdInteiros; i++) { 
        if (fread(&valor, sizeof(int), 1, file) == 1) { 
            soma += valor; 
        } 
    }

    fclose(file);

    printf("%lld", soma);

    return 0;
}