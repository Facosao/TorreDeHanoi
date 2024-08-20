#include "../menu/menus.h"

int MenuNovoJogo(void) {
  
  struct config_entrada config_menu_novojogo;
  config_menu_novojogo = InicialziarConfig();
  config_menu_novojogo.num_items   = NUM_ELEM_MENU_NOVOJOGO;
  
  while (true) {
    ImprimirDificuldade(config_menu_novojogo.opcao_atual);
    
    switch (SelecionarOpcao(&config_menu_novojogo)) {
      case APERTOU_ESC:
        return 0;
      
      case MUITO_FACIL:
        return NovoJogo(3); // 3 discos
      
      case FACIL:
        return NovoJogo(4); // 4 discos
      
      case MEDIO:
        return NovoJogo(5); // 5 discos
      
      case DIFICIL:
        return NovoJogo(7); // 7 discos
    }
  }

  return 0;
}

int MenuPausa(jogo_hanoi *jogo, bool *jogo_rodando) {

  ConfigurarTerminalMenu();
  
  struct config_entrada config_menu_pausa;
  config_menu_pausa = InicialziarConfig();
  config_menu_pausa.num_items   = NUM_ELEM_MENU_PAUSA;
  
  while (true) {
    ImprimirPausa(config_menu_pausa.opcao_atual);

    switch (SelecionarOpcao(&config_menu_pausa)) {
      case APERTOU_ESC:
      case CONTINUAR_JOGO:
        ConfigurarTerminalJogo();
        return 0;
      
      case SAIR_JOGO: {
        *jogo_rodando = false;
        return 0;
      }
    }
  }

  return 0;
}

int MenuCreditos(void) {
  
  struct config_entrada config_menu_creditos;
  config_menu_creditos = InicialziarConfig();

  ImprimirCreditos();
  
  while (true) {
    if (SelecionarOpcao(&config_menu_creditos) == APERTOU_ESC)
      return 0;
  }

  return 0;
}

int MenuVenceuJogo(jogo_hanoi *jogo) {

  ConfigurarTerminalMenu();
  
  struct config_entrada config_menu_venceujogo;
  config_menu_venceujogo = InicialziarConfig();

  int qtd_mov = 2 * jogo->qtd_movimentos;
  int tempo   = jogo->tempo.segundos + (60 * jogo->tempo.minutos);
  int fator   = jogo->tamanho;

  int pontos = fator * 1000;
  pontos += (500 - qtd_mov) + (500 - tempo);
  
  ImprimirVenceuJogo(pontos);
  
  while (true) {
    if (SelecionarOpcao(&config_menu_venceujogo) == OPCAO_INICIAL_PADRAO)
      return 0;
  }

  return 0;
}