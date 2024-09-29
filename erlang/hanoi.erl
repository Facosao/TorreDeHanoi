-module(hanoi).
-export([new_game/1]).

-define(AB, 12).
-define(AC, 13).
-define(BA, 21).
-define(BC, 23).
-define(CA, 31).
-define(CB, 32).
-define(QUIT, 0).


new_game(Difficulty) ->
    TowerA = lists:seq(1, Difficulty),
    % print_game(Size, NewTA, NewTB, NewTB),
    play(Difficulty, TowerA, [], []).


play(Size, TowerA, TowerB, TowerC) ->
    {_, [Input|_]} = io:fread("", "~d"),
    {NewTA, NewTB, NewTC, Quit} = case Input of
        ?AB -> 
            {TA, TB} = move_disc(TowerA, TowerB),
            {TA, TB, TowerC, false};
        ?AC ->
            {TA, TC} = move_disc(TowerA, TowerC),
            {TA, TowerB, TC, false};
        ?BA ->
            {TB, TA} = move_disc(TowerB, TowerA),
            {TA, TB, TowerC, false};
        ?BC ->
            {TB, TC} = move_disc(TowerB, TowerC),
            {TowerA, TB, TC, false};
        ?CA ->
            {TC, TA} = move_disc(TowerC, TowerA),
            {TA, TowerB, TC, false};
        ?CB ->
            {TC, TB} = move_disc(TowerC, TowerB),
            {TowerA, TB, TC, false};
        ?QUIT ->
            {TowerA, TowerB, TowerC, true};
        _ ->
            {TowerA, TowerB, TowerC, false}
    end,
    % print_game(Size, NewTA, NewTB, NewTB),
    Victory = has_won(Size, TowerC),
    if
        Victory or Quit -> ok;
        true -> play(Size, NewTA, NewTB, NewTC)
    end.


move_disc([], Dest) -> {[], Dest};
move_disc([SH|ST], []) -> {ST, [SH]};
move_disc([SH|ST] = Src, [DH|_] = Dest) -> 
    if
        SH < DH -> {ST, [SH | Dest]};
        true -> {Src, Dest}
    end.


has_won(Size, Tower) ->
    if
        Size == length(Tower) ->
            io:format("\nCongratulations! Insert any number to start a new game. "),
            {_, _} = io:fread("", "~d"),
            true;
        true -> false
    end.
