#include <stdbool.h>

#include "terminal/terminal.h"
#include "entrada/entrada.h"
#include "menu/menus.h"
#include "menu/imprimir_menu.h"

int main(void) {

  struct termios term_original = ObterAtributosTerminal();
  InicializarTerminal(term_original);
  
  struct config_entrada config_menu_principal;

  config_menu_principal.tecla_confirmacao = ENTER;
  config_menu_principal.tecla_avancar     = SETA_BAIXO;
  config_menu_principal.tecla_voltar      = SETA_CIMA;

  config_menu_principal.num_items   = NUM_ELEM_MENU_PRINCIPAL;
  config_menu_principal.opcao_atual = OPCAO_INICIAL_PADRAO;

  bool executar_programa = true;
  bool imprimir_titulo = true;

  while (executar_programa) {
    
    if (imprimir_titulo) {
      ImprimirTitulo();
    }
    
    ImprimirMenuPrincipal(config_menu_principal.opcao_atual);

    imprimir_titulo = true;

    switch(SelecionarOpcao(&config_menu_principal)) {
      case NOVO_JOGO:
        MenuNovoJogo();        
        break;
      
      case COMO_JOGAR:
        MenuComoJogar();
        break;
      
      case CREDITOS:
        MenuCreditos();
        break;

      case APERTOU_SETA: {
        imprimir_titulo = false;
        break;
      }
      
      case SAIR:
      case APERTOU_ESC: {
        executar_programa = false;
        break;
      }
    }
  }

  RestaurarTerminal(term_original);
  system("clear");
  return 0;
}