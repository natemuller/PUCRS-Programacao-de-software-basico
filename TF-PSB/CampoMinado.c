/*
    Implementação do TF da disciplina de Programação de Software Básico
    
Por Natan de Aragão Müller - 23104739;
Data de entrega: 06/10/2025.

Propósito: Implementação do jogo campo minado utilizando a linguagem C, seguindo as regras clássicas do jogo presentes 
na wikipédia, mais detalhes no PDF do enunciado.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "escores.h"

void preparaTabuleiro(char tab[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            tab[i][j] = ' ';
        }
    }
    int bombasPostas = 0;
    while(bombasPostas < 3) {
        int linha = rand() % 5;
        int coluna = rand() % 5;
        if(tab[linha][coluna] != '*') {
            tab[linha][coluna] = '*';
            bombasPostas++;
        }
    }
}

void imprimeTabuleiro(char tab[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("|%c|", tab[i][j]);
        }
        printf("\n");
    }
}

void preencheComNumeros(char tab[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(tab[i][j] != '*') {
                int contadorBombas = 0;
                for(int x = -1; x <= 1; x++) {
                    for(int y = -1; y <= 1; y++) {
                        int novoI = i + x;
                        int novoJ = j + y;
                        if(novoI >= 0 && novoI < 5 && novoJ >= 0 && novoJ < 5) {
                            if(tab[novoI][novoJ] == '*') {
                                contadorBombas++;
                            }
                        }
                    }
                }
                if(contadorBombas > 0) {
                    tab[i][j] = '0' + contadorBombas;
                }
                else {
                    tab[i][j] = '0';
                }
            }
        }
    }
}

void revelarAdjacentes(char tab[5][5], char tab_oculto[5][5], int i, int j) {
    if (i < 0 || i >= 5 || j < 0 || j >= 5) {
        return;
    }
    if (tab_oculto[i][j] != 'X') {
        return;
    }
    if (tab[i][j] == '*') {
        return;
    }
    tab_oculto[i][j] = tab[i][j];

    if (tab[i][j] != '0') {
        return;
    }
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int ni = i + dx;
            int nj = j + dy;

            if (ni < 0 || ni >= 5 || nj < 0 || nj >= 5) {
                continue;
            }
            if (tab_oculto[ni][nj] != 'X') {
                continue;
            }
            if (tab[ni][nj] == '*') {
                continue;
            }
            if (tab[ni][nj] == '0') {
                revelarAdjacentes(tab, tab_oculto, ni, nj);
            } 
            else {
                tab_oculto[ni][nj] = tab[ni][nj];
            }
        }
    }
}



int main() {
    
    const int TOTAL = 5 * 5;
    const int BOMBAS = 3;
    char nomeJogador[TAM_NOME + 1];

    printf("Digite seu nome (maximo 20 caracteres):\n");
    fgets(nomeJogador, sizeof(nomeJogador), stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = 0;

    printf("Olá, %s!\nSelecione uma opcao dentre as listadas:\n", nomeJogador);
    printf("0 - Iniciar novo jogo\n1 - Consultar os 10 ultimos escores\n\nPara sair pressione qualquer outra tecla.\n");
    
    int selecao;
    scanf("%d", &selecao);

    if(selecao == 0) {
        printf("Jogo iniciado. Boa sorte, %s!\n", nomeJogador);
        char tab[5][5];
        int linha, coluna;
        int contador_casas_reveladas = 0;
        double escore = 0.0;

        srand((unsigned)time(NULL));

        preparaTabuleiro(tab);
        preencheComNumeros(tab);

        char tab_oculto[5][5] = {{'X', 'X', 'X', 'X', 'X'},
                                 {'X', 'X', 'X', 'X', 'X'},
                                 {'X', 'X', 'X', 'X', 'X'},
                                 {'X', 'X', 'X', 'X', 'X'},
                                 {'X', 'X', 'X', 'X', 'X'}};
        imprimeTabuleiro(tab_oculto);

        while (1) {
            printf("Digite 'r' para revelar, 'm' para marcar/desmarcar bandeira ou 's' para sair:\n");
            char acao;
            scanf(" %c", &acao);

            if (acao == 'S' || acao == 's') {
                printf("Jogo encerrado sem salvar pontuacao.\n");
                break;
            }

            printf("Insira a posicao desejada no formato 'linha, coluna'.\n");
            scanf("%d, %d", &linha, &coluna);

            if (linha < 0 || linha >= 5 || coluna < 0 || coluna >= 5) {
                printf("Posicao invalida. Insira novamente.\n");
                continue;
            }

            if (acao == 'M' || acao == 'm') {
                if (tab_oculto[linha][coluna] == 'X') tab_oculto[linha][coluna] = '+';
                else if (tab_oculto[linha][coluna] == '+') tab_oculto[linha][coluna] = 'X';
                imprimeTabuleiro(tab_oculto);
                continue;
            }

            if (acao == 'R' || acao == 'r') {
                if (tab_oculto[linha][coluna] == '+') {
                    printf("Remova a bandeira antes de revelar esta casa.\n");
                    continue;
                }

                if (tab[linha][coluna] != '*') {
                    revelarAdjacentes(tab, tab_oculto, linha, coluna);
                    imprimeTabuleiro(tab_oculto);

                    contador_casas_reveladas = 0;
                    for(int i = 0; i < 5; i++) {
                        for(int j = 0; j < 5; j++) {
                            if(tab_oculto[i][j] != 'X' && tab_oculto[i][j] != '+') {
                                contador_casas_reveladas++;
                            }
                        }
                    }

                    escore = ((100 * (double)contador_casas_reveladas) / ((5 * 5) - 3));   
                    printf("Seu escore atual eh: %.2f\n", escore);

                    if (contador_casas_reveladas == (TOTAL - BOMBAS)) {
                        printf("Voce venceu, %s. Parabens!\n", nomeJogador);
                        imprimeTabuleiro(tab);
                        adicionarPontuacao(ARQUIVO_PONTUACAO, nomeJogador, escore);
                        break;
                    }
                } else {
                    printf("Boom! Voce perdeu, bela tentativa, %s!\n", nomeJogador);
                    imprimeTabuleiro(tab);
                    adicionarPontuacao(ARQUIVO_PONTUACAO, nomeJogador, escore);
                    break;
                }
            }
        }
        return 0;
    }
    else if (selecao == 1) {
        exibirRanking(ARQUIVO_PONTUACAO);
        return 0;
    }
    else {
        printf("Ate a proxima, %s!\n", nomeJogador);
        return 0;
    }
}
