#include "../menu/imprimir_menu.h"

void ImprimirGenerico(char **opcoes, int num_elem, int opcao_selecionada) {

  for (int i = 0; i < num_elem; i++) {
    if (i == opcao_selecionada) {
      printf("\033[47m\033[30m");  // Letras pretas em fundo branco
      printf("%s", opcoes[i]); // Imprimir string
      printf("\033[37m\033[40m");  // Restaurar cores originais 
    }                          // (Letras brancas em fundo preto)
    else {
      printf("%s", opcoes[i]);
    }
    printf("\n");
  }
}

void ImprimirTitulo(void) {

  system("clear");
  
  printf("      _____                                \n");
  printf("     |_   _|                               \n");
  printf("       | |    ___   _ __  _ __   ___       \n");
  printf("       | |   / _ \\ | '__|| '__| / _ \\      \n");
  printf("       | |  | (_) || |   | |   |  __/      \n");
  printf("       \\_/   \\___/ |_|   |_|    \\___|      \n");
  printf("                    _                      \n");
  printf("                   | |                     \n");
  printf("                __| |  ___                 \n");
  printf("                / _` | / _ \\               \n");
  printf("               | (_| ||  __/               \n");
  printf("                \\__,_| \\___|               \n");
  printf("       _   _                       _       \n");
  printf("      | | | |                     (_)      \n");
  printf("      | |_| |  __ _  _ __    ___   _       \n");
  printf("      |  _  | / _` || '_ \\  / _ \\ | |      \n");
  printf("      | | | || (_| || | | || (_) || |      \n");
  printf("      \\_| |_/ \\__,_||_| |_| \\___/ |_|      \n");
  printf("\n\n\n\n\n\n\n\n");
}

void ImprimirMenuPrincipal(int opcao_selecionada) {
  
  printf("\033[%dD", 100); // Mover para a esquerda
  printf("\033[%dA", 8);   // Mover para cima
  
  char *opcoes[4];
  opcoes[0] = "                Novo  jogo                 ";
  opcoes[1] = "                Como jogar                 ";
  opcoes[2] = "                 Creditos                  ";
  opcoes[3] = "                   Sair                    ";

  const int NUM_ELEM = 4;
  
  ImprimirGenerico(opcoes, NUM_ELEM, opcao_selecionada);

  printf("\n");
  printf("[ESC]Voltar  [Enter]Selecionar  [->]Navegar\n\n\n");
}

void ImprimirDificuldade(int opcao_selecionada) {

  printf("\033[%dD", 100); // Mover o cursor para a esquerda
  printf("\033[%dA", 8);   // Mover o cursor para cima

  printf("          Escolha uma dificuldade:         \n");
  printf("                                           \n");
  
  char *opcoes[4];
  
  opcoes[0] = "                Muito facil                ";
  opcoes[1] = "                   Facil                   ";
  opcoes[2] = "                   Medio                   ";
  opcoes[3] = "                  Dificil                  ";

  const int NUM_ELEM = 4;

  ImprimirGenerico(opcoes, NUM_ELEM, opcao_selecionada);

  printf("                                           \n");
  printf("[ESC]Voltar  [Enter]Selecionar  [->]Navegar\n");
}

void ImprimirRegraUm(void) {
  
  printf("O objetivo do jogo e mover todos os discos \n");
  printf("da primeira torre para a ultima torre.     \n");
  printf("                                           \n");
  printf("          |=======================|        \n");
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
  printf("[ESC] Sair                  [Setas] Navegar\n");

  printf("\033[%dD", 100);  // Mover o cursor para a esquerda
  printf("\033[%dA", 16);   // Mover o cursor para cima
}

void ImprimirRegraDois(void) {
  
  printf("Neste jogo, so e permitido mover um disco  \n");
  printf("no topo de uma pilha por vez.              \n");
  printf("                                           \n");
  printf("                                           \n");
  printf("     "); ImprimirDisco(1, 5);
  printf("                           \n");
  printf("          v                                \n");
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
  printf("             <- (Pagina 2/3) ->            \n");
  printf("                                           \n");
  printf("[ESC] Sair                  [Setas] Navegar\n");

  printf("\033[%dD", 100);  // Mover o cursor para a esquerda
  printf("\033[%dA", 16);   // Mover o cursor para cima
}

void ImprimirRegraTres(void) {
  printf("Por fim, nao e permitido colocar um disco  \n");
  printf("maior sobre um disco menor. Divirta-se!    \n");
  printf("                                           \n");
  printf("                                           \n");
  printf("                 "); ImprimirDisco(3, 5);
  printf("               \n");
  printf("   ---         -------------------------   \n");
  printf("          v                                \n");

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
  printf("             <- (Página 3/3)               \n");
  printf("                                           \n");
  printf("[ESC] Sair                  [Setas] Navegar\n");

  printf("\033[%dD", 100);  // Mover o cursor para a esquerda
  printf("\033[%dA", 16);   // Mover o cursor para cima
}

void ImprimirCreditos(void) {
  printf("\033[%dD", 100); // Mover o cursor para a esquerda
  printf("\033[%dA", 8);   // Mover o cursor para cima

  printf("             Projeto Integrador            \n");
  printf("      da disciplina Estrutura de Dados     \n");
  printf("                                           \n");
  printf("             Desenvolvido por:             \n");
  printf("                                           \n");
  printf("       Leonardo Maciel, Matheus Silva      \n");
  printf("          Luis Andre, Luis Felipe          \n");
  printf("                                           \n");
  printf("                                           \n");
  printf("               [ESC] Voltar                \n");
}

void ImprimirPausa(int opcao_selecionada) {
  
  char *opcoes[2];

  opcoes[0] = "Voltar ao jogo   ";
  opcoes[1] = "Sair             ";

  const int NUM_ELEM = 2;

  printf("\033[%dD", 100); // Mover para a esquerda
  printf("\033[%dA", 100); // Mover para cima
  
  // -------- Topo da caixa
  printf("|======PAUSA======|\n");

  // -------- Conteúdo da caixa
  for (int i = 0; i < NUM_ELEM; i++) {
    printf("|");
    if (i == opcao_selecionada) {
      printf("\033[47m\033[30m");  // Letras pretas em fundo branco
      printf("%s", opcoes[i]); // Imprimir string
      printf("\033[37m\033[40m");  // Restaurar cores originais 
    }                          // (Letras brancas em fundo preto)
    else {
      printf("%s", opcoes[i]);
    }
    printf("|\n");
  }

  // -------- Fim da caixa
  printf("|=================|\n");
}

void ImprimirVenceuJogo(int pontos) {
  printf("|===============================|\n");
  printf("|Parabens! Voce terminou o jogo!|\n");
  printf("|                               |\n");
  printf("| Pontuacao final: %04d pontos  |\n", pontos);
  printf("|                               |\n|");
  printf("\033[47m\033[30m");    // Letras pretas em fundo branco
  printf("           Continuar           ");
  printf("\033[37m\033[40m║\n"); // Letras brancas em fundo preto 
  printf("|                               |\n");
  printf("|      [Enter]  Selecionar      |\n");
  printf("|===============================|\n");
}
