#ifndef PILHA_H
#define PILHA_H

  #include <stdio.h> // perror()
  #include <stdlib.h>
  #include <errno.h>
  
  typedef struct no {
    int elemento;
    struct no *proximo;
  } t_no;
  
  typedef struct pilha {
    unsigned int numElem;
    t_no *topo;
  } t_pilha;
  
  t_pilha *CriarPilha(void);
  void Inserir(t_pilha *pilha, int item);
  int Remover(t_pilha *pilha);
  int Espiar(t_pilha *pilha);

#endif