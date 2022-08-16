#include "../menu/imprimir_menu.h"

void ImprimirGenerico(char **opcoes, int num_elem, int opcao_selecionada) {

  for (int i = 0; i < num_elem; i++) {
    if (i == opcao_selecionada) {
      printf("\e[47m\e[30m");  // Letras pretas em fundo branco
      printf("%s", opcoes[i]); // Imprimir string
      printf("\e[37m\e[40m");  // Restaurar cores originais 
    }                          // (Letras brancas em fundo preto)
    else {
      printf("%s", opcoes[i]);
    }
    printf("\n");
  }
}

void ImprimirTitulo(void) {

  system("clear");
  
  printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");        
  printf("░████████╗░█████╗░██████╗░██████╗░███████╗░\n");
  printf("░╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝░\n");
  printf("░░░░██║░░░██║░░██║██████╔╝██████╔╝█████╗░░░\n");
  printf("░░░░██║░░░██║░░██║██╔══██╗██╔══██╗██╔══╝░░░\n");
  printf("░░░░██║░░░╚█████╔╝██║░░██║██║░░██║███████╗░\n");
  printf("░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝░\n");
  printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░██████╗░███████╗░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░██╔══██╗██╔════╝░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░██║░░██║█████╗░░░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░██║░░██║██╔══╝░░░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░██████╔╝███████╗░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░╚═════╝░╚══════╝░░░░░░░░░░░░░░\n");
  printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
  printf("░░░██╗░░██╗░█████╗░███╗░░██╗░█████╗░██╗░░░░\n");
  printf("░░░██║░░██║██╔══██╗████╗░██║██╔══██╗██║░░░░\n");
  printf("░░░███████║███████║██╔██╗██║██║░░██║██║░░░░\n");
  printf("░░░██╔══██║██╔══██║██║╚████║██║░░██║██║░░░░\n");
  printf("░░░██║░░██║██║░░██║██║░╚███║╚█████╔╝██║░░░░\n");
  printf("░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝░╚════╝░╚═╝░░░░\n");
  printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
  printf("\n\n\n\n\n\n\n\n");
}

void ImprimirMenuPrincipal(int opcao_selecionada) {
  
  printf("\e[%dD", 100); // Mover para a esquerda
  printf("\e[%dA", 8);   // Mover para cima
  
  char *opcoes[4];
  opcoes[0] = "                Novo  jogo                 ";
  opcoes[1] = "                Como jogar                 ";
  opcoes[2] = "                 Créditos                  ";
  opcoes[3] = "                   Sair                    ";

  const int NUM_ELEM = 4;
  
  ImprimirGenerico(opcoes, NUM_ELEM, opcao_selecionada);

  printf("\n");
  printf("[ESC] Sair    [↵] Selecionar   [↑↓] Navegar\n\n\n");
}

void ImprimirDificuldade(int opcao_selecionada) {

  printf("\e[%dD", 100); // Mover o cursor para a esquerda
  printf("\e[%dA", 8);   // Mover o cursor para cima

  printf("          Escolha uma dificuldade:         \n");
  printf("                                           \n");
  
  char *opcoes[4];
  
  opcoes[0] = "                Muito fácil                ";
  opcoes[1] = "                   Fácil                   ";
  opcoes[2] = "                   Médio                   ";
  opcoes[3] = "                  Difícil                  ";

  const int NUM_ELEM = 4;

  ImprimirGenerico(opcoes, NUM_ELEM, opcao_selecionada);

  printf("                                           \n");
  printf("[ESC] Voltar  [↵] Selecionar   [↑↓] Navegar\n");
}

void ImprimirRegraUm(void) {
  
  printf("O objetivo do jogo é mover todos os discos \n");
  printf("da primeira torre para a ultima torre.     \n");
  printf("                                           \n");
  printf("          ╔═══════════════════════╗        \n");
  printf("          ↑                       ↓        \n");
  printf("                                           \n");
  
  for (int i = 0; i <= 5; ++i) {
    printf("     ");
    ImprimirDisco(i, 5);
    printf(" ");
    ImprimirDisco(0, 5);
    printf(" ");
    ImprimirDisco(0, 5);
    printf("   \n");
  }

  printf("                                           \n");
  printf("                (Página 1/3) →             \n");
  printf("                                           \n");
  printf("[ESC] Sair                    [← →] Navegar\n");

  printf("\e[%dD", 100);  // Mover o cursor para a esquerda
  printf("\e[%dA", 16);   // Mover o cursor para cima
}

void ImprimirRegraDois(void) {
  
  printf("Neste jogo, só é permitido mover um disco  \n");
  printf("no topo de uma pilha por vez.              \n");
  printf("                                           \n");
  printf("                                           \n");
  printf("     "); ImprimirDisco(1, 5);
  printf("                           \n");
  printf("          ↓                                \n");
  printf("                                           \n");

  int arrayA[5] = {2, 0, 0, 0, 0};
  int arrayB[5] = {3, 0, 0, 0, 0};
  int arrayC[5] = {5, 4, 0, 0, 0};
  
  for (int i = 4; i >= 0; --i) {
    printf("     ");
    ImprimirDisco(arrayA[i], 5);
    printf(" ");
    ImprimirDisco(arrayB[i], 5);
    printf(" ");
    ImprimirDisco(arrayC[i], 5);
    printf("   \n");
  }

  printf("                                           \n");
  printf("              ← (Página 2/3) →             \n");
  printf("                                           \n");
  printf("[ESC] Sair                    [← →] Navegar\n");

  printf("\e[%dD", 100);  // Mover o cursor para a esquerda
  printf("\e[%dA", 16);   // Mover o cursor para cima
}

void ImprimirRegraTres(void) {
  printf("Por fim, não é permitido colocar um disco  \n");
  printf("maior sobre um disco menor. Divirta-se!    \n");
  printf("                                           \n");
  printf("                                           \n");
  printf("                 "); ImprimirDisco(3, 5);
  printf("               \n");
  printf("   ---         -------------------------   \n");
  printf("          ↓                                \n");

  int arrayA[5] = {5, 4, 0, 0, 0};
  int arrayB[5] = {2, 0, 0, 0, 0};
  int arrayC[5] = {1, 0, 0, 0, 0};
  
  for (int i = 4; i >= 0; --i) {
    printf("     ");
    ImprimirDisco(arrayA[i], 5);
    printf(" ");
    ImprimirDisco(arrayB[i], 5);
    printf(" ");
    ImprimirDisco(arrayC[i], 5);
    printf("   \n");
  }

  printf("                                           \n");
  printf("              ← (Página 3/3)               \n");
  printf("                                           \n");
  printf("[ESC] Sair                    [← →] Navegar\n");

  printf("\e[%dD", 100);  // Mover o cursor para a esquerda
  printf("\e[%dA", 16);   // Mover o cursor para cima
}

void ImprimirCreditos(void) {
  printf("\e[%dD", 100); // Mover o cursor para a esquerda
  printf("\e[%dA", 8);   // Mover o cursor para cima

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
  
  char *opcoes[2];

  opcoes[0] = "Voltar ao jogo   ";
  opcoes[1] = "Sair             ";

  const int NUM_ELEM = 2;

  printf("\e[%dD", 100); // Mover para a esquerda
  printf("\e[%dA", 100); // Mover para cima
  
  // -------- Topo da caixa
  printf("╔══════PAUSA══════╗\n");

  // -------- Conteúdo da caixa
  for (int i = 0; i < NUM_ELEM; i++) {
    printf("║");
    if (i == opcao_selecionada) {
      printf("\e[47m\e[30m");  // Letras pretas em fundo branco
      printf("%s", opcoes[i]); // Imprimir string
      printf("\e[37m\e[40m");  // Restaurar cores originais 
    }                          // (Letras brancas em fundo preto)
    else {
      printf("%s", opcoes[i]);
    }
    printf("║\n");
  }

  // -------- Fim da caixa
  printf("╚═════════════════╝\n");
}

void ImprimirVenceuJogo(int pontos) {
  printf("╔═══════════════════════════════╗\n");
  printf("║Parabéns! Você terminou o jogo!║\n");
  printf("║                               ║\n");
  printf("║ Pontuação final: %04d pontos  ║\n", pontos);
  printf("║                               ║\n║");
  printf("\e[47m\e[30m");    // Letras pretas em fundo branco
  printf("           Continuar           ");
  printf("\e[37m\e[40m║\n"); // Letras brancas em fundo preto 
  printf("║                               ║\n");
  printf("║        [↵] Selecionar         ║\n");
  printf("╚═══════════════════════════════╝\n");
}