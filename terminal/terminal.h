#ifndef TERMINAL_H
#define TERMINAL_H

  #include <stdio.h>   // InicializarTerminal 
  #include <termios.h> // termios, TCSANOW, ECHO, ICANON
  #include <unistd.h>  // STDIN_FILENO

  struct termios ObterAtributosTerminal(void);
  void InicializarTerminal(struct termios terminal_atual);
  void RestaurarTerminal(struct termios term_original);
  void ConfigurarTerminalJogo(void);
  void ConfigurarTerminalMenu(void);

#endif