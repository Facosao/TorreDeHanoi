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
    Vermelho =  41,
     Laranja =  43,
     Amarelo = 103,
       Verde =  42,
        Azul =  44,
      Indigo =  45,
     Violeta = 106,
       Preto =  40,
      Branco =  47
  };
  
  void ImprimirJogo(jogo_hanoi *jogo);
  int ImprimirHUD(jogo_hanoi *jogo);
  int NumeroImpar(int n);
  void ImprimirDisco(int elemento, int tamanho);
  void EscolherCor(int disco);

#endif