#include "../pilha/pilha.h"

t_pilha *CriarPilha(void) {
  t_pilha *nova_pilha = malloc(sizeof(t_pilha));

  if (nova_pilha == NULL) {
    perror("ERRO FATAL");
    exit(EXIT_FAILURE);
  }
  
  nova_pilha->numElem = 0;
  nova_pilha->topo    = NULL;

  return nova_pilha;
}

void Inserir(t_pilha *pilha, int item) {
  
  t_no *novo_no = malloc(sizeof(t_no));

  if (novo_no == NULL) {
    perror("ERRO FATAL");
    exit(EXIT_FAILURE);
  }

  novo_no->elemento = item;
  novo_no->proximo  = pilha->topo;

  pilha->topo    = novo_no;
  pilha->numElem = (pilha->numElem + 1);
}

int Remover(t_pilha *pilha) {
  if (pilha->topo == NULL) { // Pilha vazia
    return 0;
  }
  else {
    int item_aux       = pilha->topo->elemento;
    t_no *ponteiro_aux = pilha->topo->proximo;

    free(pilha->topo);

    pilha->topo    = ponteiro_aux;
    pilha->numElem = (pilha->numElem - 1);

    return item_aux;
  }
}

int Espiar(t_pilha *pilha) {
  if (pilha->topo == NULL)
    return 0;
  else
    return pilha->topo->elemento;
}