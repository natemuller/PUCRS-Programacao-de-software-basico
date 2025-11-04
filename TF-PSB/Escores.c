#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escores.h"

void bubbleSort(RegistroPontuacao registros[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (registros[j].escore > registros[i].escore) {
                RegistroPontuacao temp = registros[i];
                registros[i] = registros[j];
                registros[j] = temp;
            }
        }
    }
}

int carregarPontuacoes(const char *caminho, RegistroPontuacao p[], int maximo) {
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        return 0; 
    }
    int n = 0;
    while (n < maximo && fscanf(arquivo, "%lf;%20[^\n]\n", &p[n].escore, p[n].nome) == 2) {
        n++;
    }

    fclose(arquivo);
    return n;
}

void adicionarPontuacao(const char *caminho, const char *nomeJogador, double escore) {
    RegistroPontuacao registros[MAX_ESCORES + 1];
    int n = carregarPontuacoes(caminho, registros, MAX_ESCORES);

    registros[n].escore = escore;
    strncpy(registros[n].nome, nomeJogador, TAM_NOME);
    registros[n].nome[TAM_NOME] = '\0';
    n++;

    bubbleSort(registros, n);

    if (n > MAX_ESCORES) n = MAX_ESCORES;

    FILE *arquivo = fopen(caminho, "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar pontuações.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%.2f;%s\n", registros[i].escore, registros[i].nome);
    }

    fclose(arquivo);
}

void exibirRanking(const char *caminho) {
    RegistroPontuacao registros[MAX_ESCORES];
    int n = carregarPontuacoes(caminho, registros, MAX_ESCORES);

    if (n == 0) {
        printf("\nSem pontuações registradas.\n");
        return;
    }

    printf("\nTop 10 escores:\n");
    for (int i = 0; i < n; i++) {
        printf("%2d) %-20s %.2f\n", i + 1, registros[i].nome, registros[i].escore);
    }
}
