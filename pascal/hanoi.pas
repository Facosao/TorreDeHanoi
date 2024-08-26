unit hanoi;

interface

uses
    hanoiRecord,
    graficos,
    stack;

procedure newGame(difficulty: integer);
procedure gameLoop(game: PHanoi);

implementation

const
    TOWER_A = 0;
    TOWER_B = 1;
    TOWER_C = 2;

    AB = 12;
    AC = 13;

    BA = 21;
    BC = 23;

    CA = 31;
    CB = 32;

    QUIT = 0;

procedure newGame(difficulty: integer);

var
    game: THanoi;
    i: integer;

begin
    game.size := difficulty;
    
    for i := 0 to 2 do
        game.towers[i] := stack.new();

    for i := difficulty downto 1 do
        stack.push(@game.towers[TOWER_A], i);

    gameLoop(@game);
end;

procedure gameLoop(game: PHanoi);

var
    gameRunning: boolean = true;
    temp, input: integer;
    srcTower, destTower: integer;
    src, dest: integer; 
    i: integer;
    auxNode, auxNext: ^TNode;
    auxStack: TStack;

begin
    printGame(game);

    while gameRunning do
    begin
        // Input and logic
        read(input);
        case input of
            AB, AC, BA, BC, CA, CB:
            begin
                srcTower := (input div 10) - 1;
                destTower := (input mod 10) - 1;

                src := stack.peek(@game^.towers[srcTower]);
                dest := stack.peek(@game^.towers[destTower]);

                if (src <> 0) and ((src < dest) or (dest = 0)) then
                begin
                    temp := stack.pop(@game^.towers[srcTower]);
                    stack.push(@game^.towers[destTower], temp);
                end;
            end;

            QUIT:
                gameRunning := false;
        end;
        
        // ----- Graphics -----
        printGame(game);

        // ----- Victory? -----
        if game^.towers[TOWER_C].size = game^.size then
        begin
            write(#10'Congratulations! Type any number to return to the main menu. ');
            read(i);
            gameRunning := false;
        end;
    end;

    // Free stack nodes
    for i := 0 to 2 do
    begin
        auxStack := game^.towers[i];
        auxNode := auxStack.top;

        while auxNode <> nil do
        begin
            auxNext := auxNode^.next;
            freeMem(auxNode);
            auxNode := auxNext;
        end;
    end;
end;

end.
