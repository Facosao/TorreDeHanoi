unit menu;

interface

uses
	hanoi,
	entrada;

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
function pausa(var jogoRodando: boolean): integer;
function menuCreditos(): integer;
function venceuJogo(): integer;

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
		writeLn('3 - Quit game'#10);
		write('Select an option: ');
		read(input);

		case input of
			NOVO_JOGO: newGame();
			CREDITOS: menuCreditos();
			SAIR: break;
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
		writeLn('Difficulty levels:'#10);
		writeLn('1 - Very easy');
		writeLn('2 - Easy');
		writeLn('3 - Medium');
		writeLn('4 - Hard'#10);
		writeLn('0 - Back to previous menu'#10);
		write('Select an option: ');
		read(input);

		case input of

			VERY_EASY:
			begin
				hanoi.newGame(3);
				exit;
			end;

			EASY:
			begin
				hanoi.newGame(4);
				exit;
			end;

			MEDIUM:
			begin
				hanoi.newGame(5);
				exit;
			end;

			HARD:
			begin
				hanoi.newGame(7);
				exit;
			end;

			PREVIOUS_MENU: exit;

			else
				continue;
		end;
	end;
end;

function pausa(var jogoRodando: boolean): integer;

var
	config: ConfigEntrada;

begin
	// ConfigurarTerminalMenu()

	config := InicializarConfig();
	config.numItems := NUM_ELEM_MENU_PAUSA;

	while true do
	begin
		//imprimirPausa(config.opcaoAtual);

		case selecionarOpcao(config) of
			// APERTOU_ESC, CONTINUAR_JOGO:
			
			SAIR_JOGO:
			begin
				jogoRodando := false;
				exit;
			end;
		end;
	end;

	pausa := 0;
end;

function menuCreditos(): integer;

var
	config: ConfigEntrada;

begin
	config := InicializarConfig();

	// ImprimirCreditos();

	while true do
		if selecionarOpcao(config) = PREVIOUS_MENU then
			exit(0);

	menuCreditos := 0;
end;

function venceuJogo(): integer;
begin
	venceuJogo := 0;
end;

end.
