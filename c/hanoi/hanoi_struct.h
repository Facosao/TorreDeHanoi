#ifndef HANOI_STRUCT_H
#define HANOI_STRUCT_H

#include "../pilha/pilha.h"

struct Relogio {
  int segundos;
  int minutos;
};

typedef struct hanoi {
  int qtd_movimentos;
  int tamanho;
  struct Relogio tempo;
  int temp;
  int torre_escolhida;
  t_pilha *torres[3];
} jogo_hanoi;

#endif