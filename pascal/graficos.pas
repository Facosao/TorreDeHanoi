unit graficos;

interface

uses 
    hanoiRecord,
    stack;

function numeroImpar(n: integer): integer;
procedure escolherCor(disco: integer);
procedure imprimirDisco(disco, tamanho: integer);
procedure printGame(game: PHanoi);

implementation

const
    PRETO    = 40;
    VERMELHO = 41;
    VERDE    = 42;
    LARANJA  = 43;
    AZUL     = 44;
    MAGENTA  = 45;
    CIANO    = 46;
    BRANCO   = 47;

function numeroImpar(n: integer): integer;
begin
    numeroImpar := (2 * n) + 1;
end;

procedure escolherCor(disco: integer);

const
    cores: array[0..5] of integer = (CIANO, AZUL, VERDE, LARANJA, VERMELHO, MAGENTA);

begin
    if disco = PRETO then
    begin
        write(#27'[', PRETO, 'm');
        exit;
    end;

    if disco = BRANCO then
    begin
        write(#27'[', BRANCO, 'm');
        exit;
    end;

    disco -= 1;
    disco := disco mod 6;

    write(#27'[', cores[disco], 'm');
end;

procedure imprimirDisco(disco, tamanho: integer);

var
    maiorDisco, centro: integer;
    i: integer;
    tamDisco, qtdEspaco: integer;

begin
    if disco = 0 then
    begin
        maiorDisco := numeroImpar(tamanho);
        centro := (maiorDisco - 1) div 2;

        for i := 0 to maiorDisco - 1 do
        begin
            if i = centro then
                escolherCor(BRANCO)
            else
                escolherCor(PRETO);

            write(' ');
        end;
    end
    else
    begin
        tamDisco := numeroImpar(disco);
        qtdEspaco := (numeroImpar(tamanho) - tamDisco) div 2;
            
        escolherCor(PRETO);
        
        for i := 0 to qtdEspaco - 1 do
            write(' ');
        
        escolherCor(disco);

        for i := 0 to tamDisco - 1 do
            write(' ');

        escolherCor(PRETO);

        for i := 0 to qtdEspaco - 1 do
            write(' ');
    end;
end;

procedure cursorUp(n: integer);
begin
    write(#27'[', n, 'A');
end;

procedure cursorDown(n: integer);
begin
    write(#27'[', n, 'B');
end;

procedure cursorRight(n: integer);
begin
    write(#27'[', n, 'C');
end;

procedure cursorLeft(n: integer);
begin
    write(#27'[', n, 'D');
end;

procedure printGame(game: PHanoi);

var
    size, numDisc: integer; 
    i, j: integer;
    auxNode: ^TNode;

begin
    write(#27'[2J'#27'[H'); // Clear screen
    size := game^.size;
    
    for i := 0 to 2 do
    begin
        numDisc := game^.towers[i].size;

        // Print blank disc spaces on the tower
        for j := size downto numDisc + 1 do
        begin
            imprimirDisco(0, size);
            cursorDown(1);
            cursorLeft(numeroImpar(size));
        end;

        //write('1');

        // Print discs
        auxNode := game^.towers[i].top;
        //write('2');

        while auxNode <> nil do
        begin
            //write('i = ', i);
            //write('element = ', game^.towers[0].top^.element);
            imprimirDisco(auxNode^.element, size);
            //write('3');
            cursorDown(1);
            cursorLeft(numeroImpar(size));
            auxNode := auxNode^.next;
            //write('4');
        end;

        // Undo last cursor movement
        cursorUp(1);
        cursorRight(numeroImpar(size));

        // Prepare for next tower
        cursorRight(1);
        cursorUp(size - 1);
    end;

    write(#10);
end;

//var
//    teste: array[0..5] of integer = (1, 2, 3, 4, 5, 6);
//    i: integer;
//    c1, c2, c3: char;
//
//begin
//    for i := 0 to 5 do
//    begin
//        imprimirDisco(teste[i], 6);
//        write(#10);
//    end;
end.