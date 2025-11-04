#ifndef ESCORES_H
#define ESCORES_H

#define ARQUIVO_PONTUACAO "escores.txt"
#define MAX_ESCORES 10
#define TAM_NOME 20

typedef struct {
    double escore;
    char nome[TAM_NOME + 1];
} RegistroPontuacao;

int carregarPontuacoes(const char *caminho, RegistroPontuacao p[], int maximo);
void adicionarPontuacao(const char *caminho, const char *nomeJogador, double escore);
void exibirRanking(const char *caminho);

#endif
