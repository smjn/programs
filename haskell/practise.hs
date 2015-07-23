---Factorial-------------------
myFactorial :: Int -> Int
myFactorial 0 = 1
myFactorial n = n * myFactorial (n-1)
---------Add 2 Vectors-----------
addVectors :: (Double, Double)->(Double, Double)->(Double,Double)
addVectors (x1, y1) (x2, y2) = (x1+x2, y1+y2)
--------Third element in tuple---
third :: (a,b,c)->c
third (_,_,c) = c
-------As Pattern----------------
asPattern :: String -> String
asPattern all@(x:y:ys) = all++" shows "++[x,y]++ys
------Initials-------------------
initials :: String->String->String
initials fname lname = [f] ++ "." ++ [l] ++ "."
	where	(f:_) = fname
		(l:_) = lname
------Square List----------------
squareList :: [Int] -> [Int]
squareList [] = [mysquare x | x<-[2]]
	where mysquare x = x*x
-------Describe List-------------
describeList :: [a]->String
describeList ls = "The List is " ++ case ls of 	[] -> "empty"
						[x] -> "singleton"
						xs -> "long list"
------Replicate------------------
myReplicate :: Int->a->[a]
myReplicate a b	|a<=0 = []
		|otherwise = (b:myReplicate (a-1) b)
------Take-----------------------
myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake n (x:xs)
	|n<=0 = []
	|otherwise = x:(myTake (n-1) xs)
-------Compare with 100----------
compareWith100 :: Int->Ordering
compareWith100 = compare 100
-------HOF apply twice-----------
applyTwice :: (a->a)->a->a
applyTwice f x = f (f x)
-------Zip with hof--------------
--zipWith' :: (a->b->c)->[a]->[b]->[c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y:zipWith' f xs xs		
-------Flip hof------------------
flip' :: (a->b->c)->(b->a->c)
flip' f = g
	where g x y = f y x
------Filter---------------------
filter' :: (a->Bool)->[a]->[a]
filter' _ [] = []
filter' f (x:xs)
	|f x = x:filter' f xs
	|otherwise = filter' f xs
------Lambda---------------------
numChain :: Num a => [[a]]->Int
numChain l = length (filter (\l -> length l > 15) l)
-------Foldr -> map--------------
map' :: (a->b)->[a]->[b]
map' f l = foldr (\x acc -> f x:acc)  [] l
-------Foldl -> map--------------
map'' :: (a->b)->[a]->[b]
map'' f = foldl (\acc x -> acc ++ [f x]) []
------Foldr ->`elem`-------------
elem' :: (Eq a) => a->[a]->Bool
elem' e l = foldr f False l
	where f x acc = (if x == e then True else acc)
------Foldr -> reverse-----------
reverse' :: [a] -> [a]
reverse' l = foldr (\x acc -> acc ++ [x]) [] l
-----Foldr ->Filter--------------
filter'' :: (a->Bool)->[a]->[a]
filter'' f l = foldr (\x acc -> (if f x == True then x:acc else acc)) [] l
