fib = 0:1:[x + y | x <- fib, y <- (tail fib)]

fib2 = 0:1:[x+y | (x,y) <- zip fib (tail fib2)]

map2 :: (a->b)->[a]->[b]
map2 f = foldr (\x xs -> f x:xs) []

dropWhile' p xs = (dropWhile p xs,xs)

data Btree a = Leaf a | Fork2 (Btree a) (Btree a)

size (Leaf x) = 1
size (Fork2 xt yt) = 1 + size xt + size yt

mirror (Leaf x) = Leaf x
mirror (Fork2 xt yt) = Fork2 (mirror yt) (mirror xt)

flatten (Leaf x) = [x]
flatten (Fork2 xt yt) = flatten xt ++ flatten yt

flatten2 t = flatten' t []
            where flatten' (Leaf x) l = x:l
                  flatten' (Fork2 xt yt) l = flatten' xt (flatten' yt l)

data Stree a = Null | Fork a (Stree a) (Stree a) deriving (Show)

flattens Null = []
flattens (Fork x xt yt) = flattens xt ++ [x] ++ flattens yt

member x Null = False
member x (Fork y xt yt)
    |x<y = member x xt
    |x==y = True
    |x>y = member x yt
           
delete x Null = Null
delete x (Fork y xt yt)
    |x<y = Fork y (delete x xt) yt
    |x==y = join xt yt
    |x>y = Fork y xt (delete x yt)

join xt yt
    |xt == Null = yt
    |otherwise = Fork x t yt
    where
      (x,t) = split xt

split (Fork x xt yt)
    |yt==Null = (x,xt)
    |otherwise = (y,Fork x xt t)
    where
      (y,t) = split yt

insert x Null = Fork x Null Null
insert x t@(Fork y xt yt)
    |x<y = Fork y (insert x xt) yt
    |x==y = t
    |x>y = Fork y xt (insert x yt)
           




