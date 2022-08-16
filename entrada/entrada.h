  #ifndef ENTRADA_H
#define ENTRADA_H

  #include <unistd.h>
  
  enum Teclas {
    ESC = 27,
    SETA_CIMA = 183,
    SETA_BAIXO = 184,
    SETA_DIREITA = 185,
    SETA_ESQUERDA = 186,
    ENTER = 10,
    ESPACO = 32
  };

  struct config_entrada {
    int tecla_confirmacao;
    int tecla_avancar;
    int tecla_voltar;

    int num_items;
    int opcao_atual;
  };
  
  int SelecionarOpcao(struct config_entrada *config);

#endif