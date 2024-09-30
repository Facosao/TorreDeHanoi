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
    graphics:print_game(Difficulty, TowerA, [], []),
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
    graphics:print_game(Size, NewTA, NewTB, NewTC),
    Victory = has_won(Size, TowerC),
    case Victory or Quit of
        true -> ok;
        false -> play(Size, NewTA, NewTB, NewTC)
    end.


move_disc([], Dest) -> {[], Dest};
move_disc([SH|ST], []) -> {ST, [SH]};
move_disc([SH|ST] = Src, [DH|_] = Dest) -> 
    case SH < DH of
        true -> {ST, [SH | Dest]};
        false -> {Src, Dest}
    end.


has_won(Size, Tower) ->
    case Size == length(Tower) of
        true ->
            io:format("\nCongratulations! Insert any number to start a new game. "),
            {_, _} = io:fread("", "~d"),
            true;
        false -> false
    end.
