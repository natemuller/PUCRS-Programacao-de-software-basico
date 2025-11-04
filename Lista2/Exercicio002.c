/*  
Exercicio002.c

Feito por Natan de Aragão Müller no dia 15/08/2025 às 14h41

Enunciado: Escreva uma func ̧  ̃ao em C que receba um tempo em total de segundos desde a meia-noite (um valor maior ou
igual a 0 e menor ou igual a 86399), retornando por refer ˆencia o n  ́umero de horas, de minutos e de segundos
correspondentes
*/

#include <stdio.h>

void hms(unsigned seg, unsigned *h, unsigned *m, unsigned *s) {
  
  *h = seg / 3600;
  seg %= 3600;

  *m = seg / 60;
  seg %= 60;

  *s = seg;
}

int main() {
  unsigned seg, h, m, s;
  scanf("%u", &seg);
  hms(seg, &h, &m, &s);
  printf("%u %u %u\n", h, m, s);
  return 0;
}
