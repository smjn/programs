max_scount l
	|null l = []
	|otherwise = (surpass (head l) (tail l) 0):max_scount (tail l)
	where
		surpass x xs n = if (null xs) then n else (if (head xs)>x then surpass x (tail xs) (n+1) else surpass x (tail xs) n)
