-module(main).
-export([start/0]).

start() ->
    io:format("Hello Erlang!\n"),
    graphics:clear_screen(),
    io:format("Tower of Hanoi - Erlang Edition\n"),
    io:format("Insert a number between 3 and 10 to start the game with that many discs.\n"),
    io:format("Insert 0 to quit the game.\n\n"),
    io:format("Select an option: "),
    {_, [Input|_]} = io:fread("", "~d"),
    case Input of
        X when X >= 3, X =< 10 ->
            hanoi:new_game(X),
            start();
        Y when Y == 0 ->
            ok;
        _ -> 
            start()
    end.

%% Compile the game:
%% erlc.exe .\graphics.erl .\hanoi.erl .\main.erl
%%
%% Run the game:
%% werl -run main -noshell -s init stop