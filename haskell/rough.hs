type Matrix = [[a]]
type Board  = Matrix Int
 --we have [[1,2],[3,4,5],[6,7]]
--we need [[1,3,6],[1,4,6],[1,5,6],...,[2,5,7]] ---cartesian product
cp :: [[a]] -> [[a]]
cp [] = [[]]	--as we want to generate from [[2,3,4]] output [[2],[3],[4]]
cp (x:xs) = [h:t | h <- x, t <- cp xs]

mcp = cp.(map cp)

--pruning a list
--initially we suggested to take the choices for blank cell to be [1..9]
--but we can limit these by pruning items from this list.
--Suppose in the same column we have 6 and 7 in same row, we can have [1234589]

fixed::[[a]] -> [a]	--first we'll produce the list of fixed items
fixed [] = []
fixed ([x]:xs) = x:fixed xs
fixed (_:xs) = fixed xs

--prune will use fixed
prune::Eq a => Matrix a -> Matrix a
prune l = [f x | x <- l]
  where f x = if length x == 1 then x else filter (\x -> not (x `elem` (fixed l))) x
	
--minchoice finds the minimum length of non-singleton elements
minChoice = minimum.filter (\_ -> 1).concat.map (map length)



