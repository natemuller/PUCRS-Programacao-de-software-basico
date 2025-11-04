/*
Exercicio002.c, por Natan de Aragão Müller no dia 02/10/2025 às 20h32.

Enunciado: Escreva um programa em C que, inicialmente, leia um limite inferior (valor inteiro), um limite superior (valor
inteiro), um tamanho de vetor de inteiros (valor inteiro) e todos os elementos desse vetor de inteiros. Os elementos
do vetor devem ser armazenados em um vetor alocado dinamicamente, uma vez que não está definido qual
o tamanho máximo deste vetor. A seguir, crie um novo vetor, também alocado dinamicamente, que contenha
apenas os elementos do vetor lido cujos valores sejam maiores ou iguais ao limite inferior lido e menores ou iguais
ao limite superior lido. Ordene este novo vetor e mostre o novo vetor ordenado, preferencialmente, em linhas
com 10 valores no máximo em cada linha. Este programa deve obrigatoriamente utilizar alocação dinâmica e toda
memória alocada dinamicamente deve ser explicitamente desalocada
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

int main() {
    int limite_inf, limite_sup, n;
    scanf("%d %d %d", &limite_inf, &limite_sup, &n);

    int *vet = (int *)malloc(n * sizeof(int));
    if (!vet) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] >= limite_inf && vet[i] <= limite_sup) {
            cont++;
        }
    }

    int *novo = (int *)malloc(cont * sizeof(int));
    if (!novo) {
        free(vet);
        return 1;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] >= limite_inf && vet[i] <= limite_sup) {
            novo[j++] = vet[i];
        }
    }

    bubbleSort(novo, cont);

    for (int i = 0; i < cont; i++) {
        printf("%d", novo[i]);
        if ((i + 1) % 10 == 0 || i == cont - 1)
            printf("\n");
        else
            printf(" ");
    }

    free(vet);
    free(novo);

    return 0;
}
