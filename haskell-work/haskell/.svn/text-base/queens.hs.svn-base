queens 0 = [[]]
queens n = [board ++ [pos] | board <- queens (n-1),
                              pos <- [1..8],
                              safeconfig board pos]
      where safeconfig board pos = all (safepos (n,pos)) -- all is true is the expressions are true for all values. safepos will be applied to each pair of zip...
                                       (zip [1..n-1] board) --we write zip as we want to combine rows and columns now. Until now we just had a list with column numbers.
            safepos (n1,pos1) (n,pos) = pos /= pos1 &&
                                       abs (n-n1) /= abs (pos-pos1)
-------------------------------X------------------------------
twice f x = f (f x)
sq :: Int->Int
sq x = x*x

--(twice twice sq) 2 = 65536