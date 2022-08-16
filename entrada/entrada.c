#include "../entrada/entrada.h"

int SelecionarOpcao(struct config_entrada *config) {

  int opcao_atual = config->opcao_atual;
  int num_items   = config->num_items;

  char buffer[3] = { 0 };
  read(STDIN_FILENO, buffer, 3);

  int tecla = (int)buffer[0] + (int)buffer[1] + (int)buffer[2];

  switch (tecla) {
    
    case ENTER: {
      if (config->tecla_confirmacao == ENTER)
        return config->opcao_atual;
      else
        return -1;
    }
    
    case ESPACO: {
      if (config->tecla_confirmacao == ESPACO)
        return config->opcao_atual;
      else
        return -1;
    }
    
    case SETA_CIMA: {
      if (config->tecla_voltar == SETA_CIMA) {
        if (opcao_atual > 0) {
          config->opcao_atual -= 1;
        }
        else {
          config->opcao_atual = config->num_items;
        }
      }
    
      return -1;
    }
    
    case SETA_BAIXO: {
      if (config->tecla_avancar == SETA_BAIXO) {
        if (opcao_atual < num_items) {
          config->opcao_atual += 1;
        }
        else {
          config->opcao_atual = 0;
        }
      }
      return -1;
    }

    case SETA_ESQUERDA: {
      if (config->tecla_voltar == SETA_ESQUERDA) {
        if (opcao_atual > 0) {
          config->opcao_atual -= 1;
        }
        else {
          config->opcao_atual = config->opcao_atual + config->num_items;
        }
      }
    
      return -1;
    }
    
    case SETA_DIREITA: {
      if (config->tecla_avancar == SETA_DIREITA) {
        if (opcao_atual < num_items) {
          config->opcao_atual += 1;
        }
        else {
          config->opcao_atual = config->opcao_atual - config->num_items;
        }
      }
      
      return -1;
    }

    case ESC: {
      return -2;
    }
    
    default: {
      return -4;
    }
  }
}