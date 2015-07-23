--type constructor
type Parser symbol tree = [symbol]->[([symbol],tree)]
------------------------X---------------------
--parser for character a
symbola :: Parser Char Char
symbola [] = []
symbola (x:xs) | x=='a'    = [(xs,'a')]
               | otherwise = []
------------------------X---------------------
--abstracting a, the class needs only be Equitable
symbol :: Eq s => s -> Parser s s
symbol a [] = []
symbol a (x:xs) | x==a = [(xs,a)]
                | otherwise = []
------------------------X----------------------
--lexical analyser
token k xs | k==take n xs = [(drop n xs),k]
           | otherwise    = []
                            where n=length k