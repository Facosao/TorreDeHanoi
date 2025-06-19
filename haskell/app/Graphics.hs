module Graphics (clearScreen, printGame) where

black :: Int
black = 40

white :: Int
white = 47

oddNumber :: Int -> Int
oddNumber n = 2 * n + 1

clearScreen :: IO ()
clearScreen = putStr "\x1b[2J\x1b[H"

cursorUp :: Int -> IO ()
cursorUp n = putStr ("\x1b[" ++ show n ++ "A")

cursorDown :: Int -> IO ()
cursorDown n = putStr ("\x1b[" ++ show n ++ "B")

cursorRight :: Int -> IO ()
cursorRight n = putStr ("\x1b[" ++ show n ++ "C")

cursorLeft :: Int -> IO ()
cursorLeft n = putStr ("\x1b[" ++ show n ++ "D")

cursorRestore :: Int -> IO ()
cursorRestore size = do
    cursorDown 1
    cursorLeft (oddNumber size)

selectColor :: Int -> IO ()
selectColor disc
    | disc == black = printColor black
    | disc == white = printColor white
    | otherwise = printColor ((disc `mod` 6) + 1 + 40)

printColor :: Int -> IO ()
printColor color = putStr ("\x1b[" ++ show color ++ "m")

printLine :: Int -> Int -> IO ()
printLine color size = do
    selectColor color
    mapM_ (\_ -> putStr " ") [1..size]

printDisc :: Int -> Int -> IO ()
printDisc 0 size = do
    let emptySpace = oddNumber size `div` 2
    printLine black emptySpace
    printLine white 1
    printLine black emptySpace
    cursorRestore size

printDisc disc size = do
    let discSize = oddNumber disc
    let spaceCount = (oddNumber size - discSize) `div` 2
    printLine black spaceCount
    printLine disc discSize
    printLine black spaceCount
    cursorRestore size

printTower :: Int -> [Int] -> IO ()
printTower size tower = do
    let freeSpaces = [1..(size - length tower)]
    mapM_ (\_ -> printDisc 0 size) freeSpaces
    mapM_ (`printDisc` size) tower
    -- Undo last cursor movement
    cursorUp 1
    cursorRight (oddNumber size)
    -- Prepare for next tower
    cursorRight 1
    cursorUp (size - 1)

printTowerId :: Int -> Int -> IO ()
printTowerId size index
    | index > 3 = return ()
    | otherwise = do
        let discSize = oddNumber size
        let center = (discSize - 1) `div` 2
        mapM_ (\x ->
            if x == center
                then putStr (show index)
                else putStr " "
            ) [0..(discSize - 1)]
        putStr " "
        printTowerId size (index + 1)

printHud :: Int -> IO ()
printHud size = do
    printTowerId size 1
    putStr "\n\nPossible moves: 12, 13, 21, 23, 31 and 32."
    putStr "\nInsert 0 to start a new game."
    putStr "\nInsert a move: "

printGame :: Int -> [Int] -> [Int] -> [Int] -> IO ()
printGame size towerA towerB towerC = do
    clearScreen
    printTower size towerA
    printTower size towerB
    printTower size towerC
    -- Print HUD
    cursorDown size
    cursorLeft 100
    printHud size

