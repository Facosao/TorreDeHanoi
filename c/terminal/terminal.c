#include "../terminal/terminal.h"

struct termios ObterAtributosTerminal(void) {
  struct termios terminal_atual;
  tcgetattr(STDIN_FILENO, &terminal_atual);
  return terminal_atual;
}

void InicializarTerminal(struct termios terminal_atual) {   
  struct termios novo_terminal = terminal_atual;
  
  novo_terminal.c_lflag &= ~(ICANON | ECHO);
  novo_terminal.c_cc[VMIN] = 1;
  novo_terminal.c_cc[VTIME] = 1; 
  tcsetattr(STDIN_FILENO, TCSANOW, &novo_terminal);

  // Forçar fundo preto no terminal do replit
  printf("\e[40m"); // Fundo preto
  printf("\e[2J"); // Limpar tela
}

void RestaurarTerminal(struct termios term_original) {
  tcsetattr(STDIN_FILENO, TCSANOW, &term_original);
}

void ConfigurarTerminalJogo(void) {
  struct termios novo_t;

  tcgetattr(STDIN_FILENO, &novo_t);

  novo_t.c_cc[VMIN] = 0;
  novo_t.c_cc[VTIME] = 10;

  tcsetattr(STDIN_FILENO, TCSANOW, &novo_t);
}

void ConfigurarTerminalMenu(void) {
  struct termios novo_t;

  tcgetattr(STDIN_FILENO, &novo_t);

  novo_t.c_cc[VMIN] = 1;
  novo_t.c_cc[VTIME] = 1;

  tcsetattr(STDIN_FILENO, TCSANOW, &novo_t);
}