#include "../menu/menus.h"

int MenuNovoJogo(void) {
  
  struct config_entrada config_menu_novojogo;

  config_menu_novojogo.tecla_confirmacao = ENTER;
  config_menu_novojogo.tecla_avancar     = SETA_BAIXO;
  config_menu_novojogo.tecla_voltar      = SETA_CIMA;

  config_menu_novojogo.num_items   = NUM_ELEM_MENU_NOVOJOGO;
  config_menu_novojogo.opcao_atual = OPCAO_INICIAL_PADRAO;
  
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

int MenuPausa(bool *jogo_rodando) { // STRUCT JOGO NÃO É USADO NESTA FUNÇÃO !!!!!

  ConfigurarTerminalMenu();
  
  struct config_entrada config_menu_pausa;

  config_menu_pausa.tecla_confirmacao = ENTER;
  config_menu_pausa.tecla_avancar     = SETA_BAIXO;
  config_menu_pausa.tecla_voltar      = SETA_CIMA;

  config_menu_pausa.num_items   = NUM_ELEM_MENU_PAUSA;
  config_menu_pausa.opcao_atual = OPCAO_INICIAL_PADRAO;
  
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

int MenuComoJogar(void) {
  
  struct config_entrada config_menu_comojogar;

  config_menu_comojogar.tecla_confirmacao = ENTER;
  config_menu_comojogar.tecla_avancar     = SETA_DIREITA;
  config_menu_comojogar.tecla_voltar      = SETA_ESQUERDA;

  config_menu_comojogar.num_items   = NUM_ELEM_MENU_COMOJOGAR;
  config_menu_comojogar.opcao_atual = OPCAO_INICIAL_PADRAO;

  printf("\e[%dD", 100); // Mover o cursor para a esquerda
  printf("\e[%dA", 8);   // Mover o cursor para cima
  
  ImprimirRegraUm();
  
  while (true) {

    if (SelecionarOpcao(&config_menu_comojogar) == APERTOU_ESC)
      return 0;
    
    switch (config_menu_comojogar.opcao_atual) {
      case PAGINA_UM:
        ImprimirRegraUm();
        break;
      
      case PAGINA_DOIS:
        ImprimirRegraDois();
        break;
      
      case PAGINA_TRES:
        ImprimirRegraTres();
        break;
    }
  }

  return 0;
}

int MenuCreditos(void) {
  
  struct config_entrada config_menu_creditos;

  config_menu_creditos.tecla_confirmacao = ENTER;
  config_menu_creditos.tecla_avancar     = SETA_BAIXO;
  config_menu_creditos.tecla_voltar      = SETA_CIMA;

  config_menu_creditos.num_items   = 0;
  config_menu_creditos.opcao_atual = OPCAO_INICIAL_PADRAO;

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

  config_menu_venceujogo.tecla_confirmacao = ENTER;
  config_menu_venceujogo.tecla_avancar     = SETA_BAIXO;
  config_menu_venceujogo.tecla_voltar      = SETA_CIMA;

  config_menu_venceujogo.num_items   = 0;
  config_menu_venceujogo.opcao_atual = OPCAO_INICIAL_PADRAO;

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
