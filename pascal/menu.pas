unit menu;

interface

uses hanoi;

const
	// General
	PREVIOUS_MENU = 0;

	// mainMenuMenu
    NOVO_JOGO     = 1;
    CREDITOS      = 2;
    SAIR          = 3;
  
    // newGame
    VERY_EASY = 1;
    EASY      = 2;
    MEDIUM    = 3;
    HARD      = 4;
  
    // pausa
    NUM_ELEM_MENU_PAUSA = 1;

    CONTINUAR_JOGO = 0;
    SAIR_JOGO  = 1;

procedure mainMenu();
procedure newGame();
procedure menuCreditos();

implementation

procedure mainMenu();

var
	input: integer;

begin
	while true do
	begin
		write(#27'[2J'#27'[H'); // Clear screen
		writeLn('Tower of Hanoi - Pascal Edition'#10);
		writeLn('1 - New game');
		writeLn('2 - Credits');
		writeLn('0 - Quit game'#10);
		write('Select an option: ');
		read(input);

		case input of
			NOVO_JOGO: newGame();
			CREDITOS: menuCreditos();
			PREVIOUS_MENU: break;
			else
				continue;
		end;
	end;

	// Game exit.
	// Clear screen
end;

procedure newGame();

var
	input: integer;

begin
	while true do
	begin
		write(#27'[2J'#27'[H'); // Clear screen
		writeLn('Enter a number between 3 and 10 to ',
		        'start the game with that many discs.');
		writeln('Enter 0 to return to the previous screen.'#10);
		write('Select an option: ');
		read(input);

		case input of
			3..10:
			begin
				hanoi.newGame(input);
				exit;
			end;

			PREVIOUS_MENU: exit;

			else
				continue;
		end;
	end;
end;

procedure menuCreditos();

begin
	exit;
end;

end.
