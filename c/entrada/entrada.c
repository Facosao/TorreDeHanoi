#include "../entrada/entrada.h"

struct config_entrada InicialziarConfig(void) {
  struct config_entrada nova_config;

  nova_config.tecla_confirmacao = ENTER;
  nova_config.tecla_avancar = SETA_BAIXO;
  nova_config.tecla_voltar = SETA_CIMA;
  nova_config.num_items = 0;
  nova_config.opcao_atual = OPCAO_INICIAL_PADRAO;
    
  return nova_config;
} 

int SelecionarOpcao(struct config_entrada *config) {

  int opcao_atual = config->opcao_atual;
  int num_items   = config->num_items;

  char buffer[3] = { 0 };
  read(STDIN_FILENO, buffer, 3);

  int tecla = (int)buffer[0] + (int)buffer[1] + (int)buffer[2];

  switch (tecla) {

    case ENTER:
    case ESPACO:
      if (config->tecla_confirmacao == tecla)
        return config->opcao_atual;
      else
        return -1;
    
    case SETA_CIMA:
    case SETA_ESQUERDA:
      if (config->tecla_voltar == tecla) {
        if (opcao_atual > 0)
          config->opcao_atual -= 1;
        else
          config->opcao_atual = config->num_items;
      }
    
      return -1;
    
    case SETA_BAIXO:
    case SETA_DIREITA:
      if (config->tecla_avancar == tecla) {
        if (opcao_atual < num_items)
          config->opcao_atual += 1;
        else
          config->opcao_atual = 0;
      }
      return -1;

    case ESC:
      return -2;
    
    default:
      return -4;
  }
}