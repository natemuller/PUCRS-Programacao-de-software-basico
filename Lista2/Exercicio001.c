/*  
Exercicio001.c

Feito por Natan de Aragão Müller no dia 15/08/2025 às 15h01

Enunciado: Escreva uma func ̧  ̃ao em C para um caixa de banco, que recebe um valor inteiro r (maior ou igual a zero) e deter-
mina o n  ́umero de notas de 100, 50, 10, 5 e 1 reais necess  ́ario para pagar a quantia r. Fac ̧a de forma que o n  ́umero
de notas usado seja o menor poss ́ıvel, retornando as quantidades de notas por refer ˆencia.
*/

#include <stdio.h>

void papelMoeda(unsigned r, unsigned *n100, unsigned *n50, unsigned *n10, unsigned *n5, unsigned *n1) {
  *n100 = r / 100;
  r %= 100;

  *n50 = r / 50;
  r %= 50;

  *n10 = r / 10;
  r %= 10;

  *n5 = r / 5;
  r %= 5;

  *n1 = r; 
}

int main() {
  unsigned r, n100, n50, n10, n5, n1;
  scanf("%u", &r);
  papelMoeda(r, &n100, &n50, &n10, &n5, &n1);
  printf("%u %u %u %u %u\n", n100, n50, n10, n5, n1);
  return 0;
}
