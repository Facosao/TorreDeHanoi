#include "../hanoi/hanoi.h"

int NovoJogo(int dificuldade) {
  
  jogo_hanoi jogo;
  
  jogo.tamanho         = dificuldade;
  jogo.temp            = 0;
  jogo.qtd_movimentos  = 0;
  jogo.torre_escolhida = 0;
  jogo.tempo.segundos  = 0;
  jogo.tempo.minutos   = 0;
  
  for (int i = 0; i < 3; i++) {
    jogo.torres[i] = CriarPilha();
  }
  
  for (int i = dificuldade; i > 0; i--) {
    Inserir(jogo.torres[0], i);
  }
  
  return LoopJogo(&jogo);
}

int LoopJogo(jogo_hanoi *jogo) {

  struct config_entrada config_jogo_hanoi;

  config_jogo_hanoi.tecla_confirmacao = ESPACO;
  config_jogo_hanoi.tecla_avancar     = SETA_DIREITA;
  config_jogo_hanoi.tecla_voltar      = SETA_ESQUERDA;

  config_jogo_hanoi.num_items   = 2;
  config_jogo_hanoi.opcao_atual = OPCAO_INICIAL_PADRAO;
  
  ConfigurarTerminalJogo();
  
  time_t tempo_inicial = time(NULL);
  time_t pausa_total   = 0;

  ImprimirJogo(jogo); // Frame inicial
  ImprimirHUD(jogo);
  
  bool jogo_rodando = true;

  while (jogo_rodando) { // Game Loop
    
    // ----- Entrada -----

    int selecao = SelecionarOpcao(&config_jogo_hanoi);

    // ----- Lógica -----

    int temp_antigo            = jogo->temp;
    int torre_escolhida_antigo = jogo->torre_escolhida;
    
    jogo->torre_escolhida = config_jogo_hanoi.opcao_atual;
    
    switch(selecao) {
      case PAUSA: {
        time_t pausa_aux = time(NULL);
        
        MenuPausa(jogo, &jogo_rodando);
        
        pausa_aux = time(NULL) - pausa_aux;
        pausa_total += pausa_aux;

        torre_escolhida_antigo++;
        break;
      }

      case TORRE_A:
      case TORRE_B:
      case TORRE_C: {
        t_pilha *pilha_aux = jogo->torres[selecao];
        
        if (jogo->temp == 0) { // Nenhum disco sendo segurado
          jogo->temp = Remover(pilha_aux);
        }
        else {                 // Colocar disco na pilha
          if ((Espiar(pilha_aux) > jogo->temp) || (Espiar(pilha_aux) == 0)) {
            Inserir(pilha_aux, jogo->temp);
            jogo->temp = 0;
          }
        }
        break;
      }
      
    }
    
    if ((jogo->temp != temp_antigo) && (temp_antigo != 0))
      jogo->qtd_movimentos++; // Algum disco foi movido

    time_t tempo_atual = time(NULL);
    tempo_atual -= tempo_inicial + pausa_total;
    jogo->tempo.segundos = tempo_atual % 60;
    jogo->tempo.minutos  = tempo_atual / 60;

    // ----- Gráficos -----

    bool mudou_disco = (jogo->temp != temp_antigo);
    bool mudou_torre = (jogo->torre_escolhida != torre_escolhida_antigo);
          
    if (mudou_disco || mudou_torre)
      ImprimirJogo(jogo);
    
    ImprimirHUD(jogo);

    // ----- Fim do jogo -----
    
    if (jogo->torres[2]->numElem == jogo->tamanho) {
      MenuVenceuJogo(jogo);
      jogo_rodando = false;
    }
    
  } // while (jogo_rodando)

  // Liberar memória
  
  for (int i = 0; i < 3; i++) { 
    t_pilha *pilha_aux = jogo->torres[i];
    t_no *no_aux = pilha_aux->topo;

    while (no_aux != NULL) {
      t_no *ponteiro_aux = no_aux->proximo;
      free(no_aux);
      no_aux = ponteiro_aux;
    }

    free(pilha_aux);
  }
  
  return 0;
}