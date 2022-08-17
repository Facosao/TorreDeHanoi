#ifndef GRAFICOS_H
#define GRAFICOS_H

  #include <stdio.h>
  #include <stdlib.h> // system()

  #include "../hanoi/hanoi.h"

  enum ApenasEscolher {
    escolher_preto  = -2,
    escolher_branco = -1
  };

  enum CoresFundo {
       Preto =  40,
    Vermelho =  41,
       Verde =  42,
     Laranja =  43,
        Azul =  44,
      Indigo =  45,
       Ciano =  46,
      Branco =  47
  };
  
  void ImprimirJogo(jogo_hanoi *jogo);
  int ImprimirHUD(jogo_hanoi *jogo);
  int NumeroImpar(int n);
  void ImprimirDisco(int elemento, int tamanho);
  void EscolherCor(int disco);

#endif
