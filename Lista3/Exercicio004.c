/*  
Exercicio004.c

Feito por Natan de Aragão Müller no dia 27/08/2025 às 18h17

Enunciado: Considere uma estrutura (struct) para armazenar dia, mˆes e ano para determinado dia (conforme declarac ̧  ̃ao
do exemplo abaixo) e implemente duas func ̧  ̃oes em C: uma para incrementar o dia (recebendo uma vari  ́avel da
estrutura por referˆencia) e outra para mostrar o dia na sa ́ıda padr  ̃ao no formato DD/MM/AAAA (recebendo a
vari  ́avel da estrutura por valor).
*/

#include <stdio.h>

typedef struct {
  int dia, mes, ano;
} dia_t;

int bissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

void incrementa_dia(dia_t *d) {

    int dias_mes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (bissexto(d->ano)) {
        dias_mes[2] = 29;
    }
    d->dia++;

    if (d->dia > dias_mes[d->mes]) {
        d->dia = 1;
        d->mes++;
        if (d->mes > 12) {
            d->mes = 1;
            d->ano++;
        }
    }
}
void mostra_dia(dia_t d) {
  printf("%02d/%02d/%04d", d.dia, d.mes, d.ano);
}

int main() {
  dia_t d;
  scanf("%d %d %d", &d.dia, &d.mes, &d.ano);
  incrementa_dia(&d);
  mostra_dia(d);
  return 0;
}
