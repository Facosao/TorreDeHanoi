#ifndef JOGO_GERAL_H
#define JOGO_GERAL_H

  //typedef struct pilha t_pilha;
  //typedef struct hanoi jogo_hanoi;

  #include <stdbool.h>
  #include <stdlib.h> // NULL, free()
  #include <time.h>

  #include "hanoi_struct.h"
  #include "../entrada/entrada.h"
  #include "../graficos/graficos.h"
  #include "../menu/menus.h"
  #include "../terminal/terminal.h"

  enum EntradasEspeciais {
    PAUSA = -2,
    TORRE_A = 0,
    TORRE_B = 1,
    TORRE_C = 2
  };
  
  int NovoJogo(int dificuldade);
  int LoopJogo(jogo_hanoi *jogo);

#endif