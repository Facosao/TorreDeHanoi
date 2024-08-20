#include <stdbool.h>

#include "terminal/terminal.h"
#include "entrada/entrada.h"
#include "menu/menus.h"
#include "menu/imprimir_menu.h"

int main(void) {

  struct termios term_original = ObterAtributosTerminal();
  InicializarTerminal(term_original);
  
  struct config_entrada config_menu_principal;
  config_menu_principal = InicialziarConfig();
  config_menu_principal.num_items = NUM_ELEM_MENU_PRINCIPAL;

  bool executar_programa = true;

  while (executar_programa) {
    
    ImprimirTitulo();
    ImprimirMenuPrincipal(config_menu_principal.opcao_atual);

    switch(SelecionarOpcao(&config_menu_principal)) {
      case NOVO_JOGO:
        MenuNovoJogo();        
        break;
      
      case CREDITOS:
        MenuCreditos();
        break;
      
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