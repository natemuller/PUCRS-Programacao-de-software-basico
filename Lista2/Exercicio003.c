/*  
Exercicio002.c

Feito por Natan de Aragão Müller no dia 15/08/2025 às 15h15

Enunciado: Escreva uma func ̧  ̃ao em C que receba um vetor de inteiros, mais a quantidade de valores presentes nele, e retorne
um n  ́umero inteiro correspondente `a quantidade de valores que aparecem mais de uma vez. Por exemplo, se o
vetor for [1, 2, 3, 4, 5, 3, 6, 7, 2, 8], o retorno ser  ́a 2 (2 n  ́umeros se repetem, 2 e 3)
*/

#include <stdio.h>

#define MAX 100

int conta_repetidos(int *vet, int tam) {
  int contaRepetido = 0;

  for (int i = 0; i < tam; i++) {
    int jaContado = 0;
    for (int k = 0; k < i; k++) {
      if (vet[k] == vet[i]) {
        jaContado = 1;
        break;
      }
    }

    if (jaContado) {
      continue;
    }

    for (int j = i + 1; j < tam; j++) {
      if (vet[i] == vet[j]) {
        contaRepetido++;
        break; 
      }
    }
  }

  return contaRepetido;
}

int main() {
  int vet[MAX], tam;
  scanf("%d", &tam);
  if ( tam > MAX )
     return 1;
  for (int i=0; i < tam; ++i)
      scanf("%d", &vet[i]);
  printf("%d\n", conta_repetidos(vet, tam));
  return 0;
}


