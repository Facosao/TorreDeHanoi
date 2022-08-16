#ifndef IMPRIMIR_MENU_H
#define IMPRIMIR_MENU_H

  #include <stdio.h>
  #include "../graficos/graficos.h"
  
  void ImprimirGenerico(char **opcoes, int num_elem, int opcao_selecionada);

  void ImprimirTitulo(void);
  void ImprimirMenuPrincipal(int opcao_selecionada);
  void ImprimirDificuldade(int opcao_selecionada);

  void ImprimirRegraUm(void);
  void ImprimirRegraDois(void);
  void ImprimirRegraTres(void);

  void ImprimirCreditos(void);
  void ImprimirPausa(int opcao_selecionada);

  void ImprimirVenceuJogo(int pontos);

#endif