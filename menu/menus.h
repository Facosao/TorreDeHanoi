#ifndef MENUS_H
#define MENUS_H

  #include <stdio.h> // ANSI Escape codes
  #include <stdbool.h>
  
  #include "../entrada/entrada.h"
  #include "../menu/imprimir_menu.h"
  #include "../hanoi/hanoi.h"
  #include "../terminal/terminal.h"
  
  enum OpcoesMenu {
    APERTOU_ESC          = -2,
    APERTOU_SETA         = -1,
    OPCAO_INICIAL_PADRAO =  0,
  
    // MenuPrincipal
    NUM_ELEM_MENU_PRINCIPAL = 3,

    NOVO_JOGO     = 0,
    COMO_JOGAR    = 1,
    CREDITOS      = 2,
    SAIR          = 3,
  
    // MenuNovoJogo
    NUM_ELEM_MENU_NOVOJOGO = 3,
    
    MUITO_FACIL = 0,
    FACIL       = 1,
    MEDIO       = 2,
    DIFICIL     = 3,
  
    // MenuPausa
    NUM_ELEM_MENU_PAUSA = 1,

    CONTINUAR_JOGO = 0,
    SAIR_JOGO  = 1,

    // MenuComoJogar
    NUM_ELEM_MENU_COMOJOGAR = 2,

    PAGINA_UM   = 0,
    PAGINA_DOIS = 1,
    PAGINA_TRES = 2
  };
  
  int MenuNovoJogo(void);
  int MenuPausa(jogo_hanoi *jogo, bool *jogo_rodando);
  int MenuComoJogar(void);
  int MenuCreditos(void);
  int MenuVenceuJogo(jogo_hanoi *jogo);

#endif