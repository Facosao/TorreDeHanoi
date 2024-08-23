unit graficos;

interface

uses 
    hanoiRecord,
    stack;

function numeroImpar(n: integer): integer;
procedure escolherCor(disco: integer);
procedure imprimirDisco(disco, tamanho: integer);
procedure printGame(game: PHanoi);
procedure printHUD(size: integer);

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

        // Print discs
        auxNode := game^.towers[i].top;

        while auxNode <> nil do
        begin
            imprimirDisco(auxNode^.element, size);
            cursorDown(1);
            cursorLeft(numeroImpar(size));
            auxNode := auxNode^.next;
        end;

        // Undo last cursor movement
        cursorUp(1);
        cursorRight(numeroImpar(size));

        // Prepare for next tower
        cursorRight(1);
        cursorUp(size - 1);
    end;

    cursorDown(size);
    cursorLeft(100);
    printHUD(size);
end;

procedure printHUD(size: integer);

var
    largestDisc, center: integer;
    i, j, towerCounter: integer;

begin
    largestDisc := numeroImpar(size);
    center := (largestDisc - 1) div 2;
    towerCounter := 1;

    for i := 0 to 2 do
    begin
        for j := 0 to largestDisc - 1 do
        begin
            if (j mod largestDisc) = center then
            begin
                write(towerCounter);
                towerCounter += 1;
            end
            else
                write(' ');
        end;
        write(' '); // Tower space
    end;

    //writeLn('Possible moves:');
    writeLn(#10#10'12, 13, 21, 23, 31, 32 - Possible moves');
    writeLn('0 - Back to main menu'#10);
    write('Insert a move: ');
end;

end.
