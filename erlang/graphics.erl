-module(graphics).
-export([clear_screen/0, print_game/4]).

-define(BLACK, 40).
-define(WHITE, 47).


odd_number(N)        -> 2 * N + 1.
% Terminal functions 
clear_screen()       -> io:format("\e[2J\e[H").
cursor_up(N)         -> io:format("\e[~wA", [N]).
cursor_down(N)       -> io:format("\e[~wB", [N]).
cursor_right(N)      -> io:format("\e[~wC", [N]).
cursor_left(N)       -> io:format("\e[~wD", [N]).
cursor_restore(Size) -> cursor_down(1), cursor_left(odd_number(Size)).


select_color(Disc) when Disc == ?BLACK -> print_color(?BLACK);
select_color(Disc) when Disc == ?WHITE -> print_color(?WHITE);
select_color(Disc) -> print_color((Disc rem 6) + 1 + 40).


print_color(Color) -> io:format("\e[~wm", [Color]).
print_color(Color, Size) ->
    select_color(Color),
    lists:map(fun(_) -> io:format(" ") end, lists:seq(1, Size)).


print_disc(Disc, Size) when Disc == 0 ->
    EmptySpace = odd_number(Size) div 2,
    print_color(?BLACK, EmptySpace),
    print_color(?WHITE, 1),
    print_color(?BLACK, EmptySpace),
    cursor_restore(Size);

print_disc(Disc, Size) ->
    DiscSize = odd_number(Disc),
    SpaceCount = (odd_number(Size) - DiscSize) div 2,
    print_color(?BLACK, SpaceCount),
    print_color(Disc, DiscSize),
    print_color(?BLACK, SpaceCount),
    cursor_restore(Size).


print_tower(Size, Tower) ->
    FreeSpaces = lists:seq(1, Size - length(Tower)),
    lists:map(fun(_) -> print_disc(0, Size) end, FreeSpaces),
    lists:map(fun(X) -> print_disc(X, Size) end, Tower),
    % Undo last cursor movement
    cursor_up(1),
    cursor_right(odd_number(Size)),
    % Prepare for next tower
    cursor_right(1),
    cursor_up(Size - 1).


print_tower_id(Size, ID) when ID =< 3 ->
    DiscSize = odd_number(Size),
    Center = (DiscSize - 1) div 2,
    lists:map(
        fun(X) ->
            case X == Center of 
                true -> io:format("~w", [ID]);
                false -> io:format(" ")
            end
        end,
        lists:seq(0, DiscSize - 1)
    ),
    io:format(" "),
    print_tower_id(Size, ID + 1);

print_tower_id(_, _) -> ok. 

print_hud(Size) -> 
    print_tower_id(Size, 1),
    io:format("\n\nPossible moves: 12, 13, 21, 23, 31 and 32."),
    io:format("\nInsert 0 to start a new game."),
    io:format("\nInsert a move: ").


print_game(Size, TowerA, TowerB, TowerC) ->
    clear_screen(),
    print_tower(Size, TowerA),
    print_tower(Size, TowerB),
    print_tower(Size, TowerC),
    % Print HUD
    cursor_down(Size),
    cursor_left(100),
    print_hud(Size).
