module Main where

import System.IO ( hFlush, stdout )
import Graphics (clearScreen)
import Hanoi (newGame)

readInt :: IO Int
readInt = readLn

main :: IO ()
main = do
    clearScreen
    putStr "Tower of Hanoi - Haskell Edition\n"
    putStr "Insert a number between 3 and 10 to start the game with that many discs.\n"
    putStr "Insert 0 to quit the game.\n\n"
    putStr "Select an option: "
    
    hFlush stdout
    input <- readInt
    case input of
        x | x >= 3 && x <= 10 -> do
            newGame x
            main
        
        0 -> return ()
        
        _ -> main
