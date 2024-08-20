#include "../graficos/graficos.h"

void ImprimirJogo(jogo_hanoi *jogo) {

  //printf("\e[40m"); // DEBUG
  system("clear"); // Limpa tela a cada frame

  int tamanho = jogo->tamanho;
  int num_torre = jogo->torre_escolhida;

  int comeco = NumeroImpar(tamanho) * num_torre + num_torre;
  
  for (int i = 0; i < comeco; i++) {
    printf(" ");
  }
  
  ImprimirDisco(jogo->temp, jogo->tamanho);
  printf("\n\n");

  // Imprimir torres baseado no tamanho da pilha
  for (int i = 0; i < 3; i++) {
    
    int numElem = jogo->torres[i]->numElem;

    // Imprimir espaços vazios
    for (int i = tamanho; i > numElem; i--) {
      ImprimirDisco(0, tamanho);
      printf("\e[%dB", 1);                    // Descer uma linha
      printf("\e[%dD", NumeroImpar(tamanho)); // Voltar cursor para esquerda
    }

    t_pilha *pilha_atual = jogo->torres[i];
    t_pilha *pilha_temp = CriarPilha();
    
    int aux_temp = Remover(pilha_atual);
    
    while (aux_temp != 0) {
      ImprimirDisco(aux_temp, tamanho);
      printf("\e[%dB", 1);                    // Descer uma linha
      printf("\e[%dD", NumeroImpar(tamanho)); // Voltar cursor para esquerda
      Inserir(pilha_temp, aux_temp);
      aux_temp = Remover(pilha_atual);
    }

    aux_temp = Remover(pilha_temp);

    while (aux_temp != 0) {
        Inserir(pilha_atual, aux_temp);
        aux_temp = Remover(pilha_temp);
    }

    free(pilha_temp);
      
    // Colocar cursor na frente do último disco inferior
    printf("\e[%dA", 1);                    // Subir uma linha
    printf("\e[%dC", NumeroImpar(tamanho)); // Voltar cursor para direita

    // Preparar para próxima iteração
    printf("\e[%dC", 1);             // Avançar cursor para a direita
    printf("\e[%dA", (tamanho - 1)); // Subir cursor para o topo
  }
  
  printf("\e[%dB", tamanho); // Separar torres do HUD
  printf("\n\n\n\n\n\n");
}

int ImprimirHUD(jogo_hanoi *jogo) {
  printf("\e[%dD", 100); // Mover o cursor para a esquerda
  printf("\e[%dA", 6);   // Mover o cursor para cima

  printf("\nQtd. de movimentos: %d\n", jogo->qtd_movimentos);
  printf("Tempo: %d:%02d\n\n", jogo->tempo.minutos, jogo->tempo.segundos);
  printf("[ESC] Pausar  [Barra de espaço] Selecionar [← →] Navegar\n\n");
  
  return 0;
}

int NumeroImpar(int n) { // Sequência começa no 3
  return ((2 * n) + 1);
}

void ImprimirDisco(int disco, int tamanho) {
  
  if (disco == 0) { // Quando não têm um disco
    
    int maior_disco = NumeroImpar(tamanho);
    int centro = (maior_disco - 1) / 2;
    
    for (int i = 0; i < maior_disco; i++) {
      if (i == centro) {
        EscolherCor(escolher_branco);
        printf(" ");
      }
      else {
        EscolherCor(escolher_preto);
        printf(" ");
      }
    }
    
  }
  else {
    int tam_disco  = NumeroImpar(disco);
    int qtd_espaco = (NumeroImpar(tamanho) - tam_disco) / 2;
    
    for (int i = 0; i < qtd_espaco; i++) {
      EscolherCor(escolher_preto);
      printf(" ");
    }
    
    for (int i = 0; i < tam_disco; i++) {
      EscolherCor(disco);
      printf(" ");
      EscolherCor(escolher_preto);
    }
    
    for (int i = 0; i < qtd_espaco; i++) {
      EscolherCor(escolher_preto);
      printf(" ");
    }
  }  
}

void EscolherCor(int disco) {

  if (disco == (-2)) {
    printf("\e[%dm", Preto);
    return;
  }
  if (disco == (-1)) {
    printf("\e[%dm", Branco);
    return;
  }
    
  const int cores[7] = { Violeta,  Indigo, Azul, Verde,
                         Amarelo, Laranja, Vermelho};

  disco -= 1;
  disco %= 7;
  
  printf("\e[%dm", cores[disco]);
}