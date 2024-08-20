unit entrada;

interface

const
	ESC = 27;
    SETA_CIMA = 183;
    SETA_BAIXO = 184;
    SETA_DIREITA = 185;
    SETA_ESQUERDA = 186;
    ENTER = 10;
    ESPACO = 32;

type
	ConfigEntrada = record
		teclaConfirmacao: integer;
		teclaAvancar: integer;
		teclaVoltar: integer;
		numItems: integer;
		opcaoAtual: integer
	end;

function inicializarConfig(): ConfigEntrada;
function selecionarOpcao(var config: ConfigEntrada): integer;

implementation

function inicializarConfig(): ConfigEntrada;

begin
	inicializarConfig.teclaConfirmacao := ENTER;
	inicializarConfig.teclaAvancar := SETA_BAIXO;
	inicializarConfig.teclaVoltar := SETA_CIMA;
	inicializarConfig.numItems := 0;
	inicializarConfig.opcaoAtual := 0; // Opção Inicial Padrão
end;

function selecionarOpcao(var config: ConfigEntrada): integer;

var
	tecla: integer;

begin
	read(tecla);

	case tecla of
		ENTER, ESPACO: 
		begin
			if config.teclaConfirmacao = tecla then
				selecionarOpcao := config.opcaoAtual
			else
				selecionarOpcao := -1;
		end;

		SETA_CIMA, SETA_ESQUERDA:
		begin
			if config.teclaVoltar = tecla then
			begin
				if config.opcaoAtual > 0 then
					config.opcaoAtual -= 1
				else
					config.opcaoAtual := config.numItems;
			end;

			selecionarOpcao := -1;
		end;

		SETA_BAIXO, SETA_DIREITA:
		begin
			if config.teclaAvancar = tecla then
			begin
				if config.opcaoAtual < config.numItems then
					config.opcaoAtual += 1
				else
					config.opcaoAtual := 0;
			end;

			selecionarOpcao := -1;
		end;

		ESC:
			selecionarOpcao := -2;
		else
			selecionarOpcao := -4;
	end;
end;

end.
