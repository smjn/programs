--sudoku solver--
type Matrix = [[a]]

type Board = Matrix Char

--constants--
nodups [] = True
nodups (x:xs) = not (x `elem` xs) && nodups xs

rows = id
cols [] = replicate 9 []
cols (x:xs) = zipWith (:) x (cols xs)
boxes = map unchop.unchop.map cols.chop.map chop

unchop = concat

chop [] = []
chop l = take boxsize l : chop (drop boxsize l)

type Choices = [Char]



