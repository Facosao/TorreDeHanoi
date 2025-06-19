module Hanoi ( newGame ) where

import System.IO ( hFlush, stdout )
import Graphics ( printGame )

ab :: Int
ab = 12

ac :: Int
ac = 13

ba :: Int
ba = 21

bc :: Int
bc = 23

ca :: Int
ca = 31

cb :: Int
cb = 32

quit :: Int
quit = 0

readInt :: IO Int
readInt = readLn

newGame :: Int -> IO ()
newGame difficulty = do
    let towerA = [1..difficulty]
    printGame difficulty towerA [] []
    play difficulty towerA [] []

play :: Int -> [Int] -> [Int] -> [Int] -> IO ()
play size towerA towerB towerC = do
    hFlush stdout
    input <- readInt
    let (newTa, newTb, newTc, newQuit) = case input of
            x | x == ab ->
                let (ta, tb) = moveDisc towerA towerB
                in (ta, tb, towerC, False)

            x | x == ac ->
                let (ta, tc) = moveDisc towerA towerC
                in (ta, towerB, tc, False)

            x | x == ba ->
                let (tb, ta) = moveDisc towerB towerA
                in (ta, tb, towerC, False)

            x | x == bc ->
                let (tb, tc) = moveDisc towerB towerC
                in (towerA, tb, tc, False)

            x | x == ca ->
                let (tc, ta) = moveDisc towerC towerA
                in (ta, towerB, tc, False)

            x | x == cb ->
                let (tc, tb) = moveDisc towerC towerB
                in (towerA, tb, tc, False)

            x | x == quit -> (towerA, towerB, towerC, True)

            _ -> (towerA, towerB, towerC, False)

    printGame size newTa newTb newTc
    victory <- hasWon size newTc
    if victory || newQuit then
        return ()
    else
        play size newTa newTb newTc

moveDisc :: [Int] -> [Int] -> ([Int], [Int])
moveDisc [] dest    = ([], dest)
moveDisc (sh:st) [] = (st, [sh])
moveDisc src@(sh:st) dest@(dh:_)
    | sh < dh = (st, sh:dest)
    | otherwise = (src, dest)

hasWon :: Int -> [Int] -> IO Bool
hasWon size tower =
    if size == length tower then
        do
            putStr "\nCongratulations! Insert any number to start a new game. "
            hFlush stdout
            _ <- readInt
            return True
    else
        return False