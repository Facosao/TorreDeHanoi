#include "../menu/imprimir_menu.h"

void ImprimirGenerico(char **opcoes, char **window_bars, int num_elem, int opcao_selecionada) {

  printf("%s\n", window_bars[0]);

  for (int i = 0; i < num_elem; i++) {
    printf("|");
    if (i == opcao_selecionada) {
      printf("\e[47m\e[30m");  // Letras pretas em fundo branco
      printf("%s", opcoes[i]); // Imprimir string
      printf("\e[37m\e[40m");  // Restaurar cores originais 
    }                          // (Letras brancas em fundo preto)
    else {
      printf("%s", opcoes[i]);
    }
    printf("|\n");
  }

  printf("%s\n", window_bars[1]);
}

void ImprimirTitulo(void) {

  system("clear");

  printf("            ==================             \n");
  printf("            | Tower of Hanoi |             \n");
  printf("            |   C Language   |             \n");
  printf("            ==================             \n\n");
}

void ImprimirMenuPrincipal(int opcao_selecionada) {

  char *window_bars[2];
  window_bars[0] = "=============== MAIN  MENU ================";
  window_bars[1] = "===========================================";

  char *opcoes[3];
  opcoes[0] = "               Novo  jogo                ";
  opcoes[1] = "                Créditos                 ";
  opcoes[2] = "                  Sair                   ";

  const int NUM_ELEM = 3;
  
  ImprimirGenerico(opcoes, window_bars, NUM_ELEM, opcao_selecionada);

  printf("\n[ESC] Sair    [↵] Selecionar   [↑↓] Navegar\n");
}

void ImprimirDificuldade(int opcao_selecionada) {

  system("clear");
  
  char *window_bars[2];
  window_bars[0] = "================ NEW GAME =================";
  window_bars[1] = "===========================================";

  printf("          Escolha uma dificuldade:         \n");
  printf("                                           \n");
  
  char *opcoes[4];
  opcoes[0] = "               Muito fácil               ";
  opcoes[1] = "                  Fácil                  ";
  opcoes[2] = "                  Médio                  ";
  opcoes[3] = "                 Difícil                 ";

  const int NUM_ELEM = 4;

  ImprimirGenerico(opcoes, window_bars, NUM_ELEM, opcao_selecionada);

  printf("\n[ESC] Voltar  [↵] Selecionar   [↑↓] Navegar\n");
}

void ImprimirCreditos(void) {
  
  system("clear");

  printf("             Projeto Integrador            \n");
  printf("      da disciplina Estrutura de Dados     \n");
  printf("                                           \n");
  printf("             Desenvolvido por:             \n");
  printf("                                           \n");
  printf("       Leonardo Maciel, Matheus Silva      \n");
  printf("          Luis André, Luis Felipe          \n");
  printf("                                           \n");
  printf("                                           \n");
  printf("               [ESC] Voltar                \n");
}

void ImprimirPausa(int opcao_selecionada) {

  char *window_bars[2];
  window_bars[0] = "====== PAUSE ======";
  window_bars[1] = "===================";
  
  char *opcoes[2];
  opcoes[0] = "Voltar ao jogo   ";
  opcoes[1] = "Sair             ";

  const int NUM_ELEM = 2;

  printf("\e[%dD", 100);  // Mover para a esquerda
  printf("\e[%dA", 100);  // Mover para cima
  
  ImprimirGenerico(opcoes, window_bars, NUM_ELEM, opcao_selecionada);
}

void ImprimirVenceuJogo(int pontos) {

  char *window_bars[2];
  window_bars[0] = "======== Congratulations ========";
  window_bars[1] = "=================================";

  char *options[4];
  options[0] = "       You won the game!       ";
  options[1] = "    Final score: 0000 points   ";
  options[2] = "                               ";
  options[3] = "       [ENTER] Continue        ";

  const int NUM_ELEM = 4;

  ImprimirGenerico(options, window_bars, NUM_ELEM, 3);
}