type Parser symbol result = [symbol]->[([symbol],result)]
-------String -------------
token k xs
	|k == (take n xs) = [(drop n xs, k)]
	|otherwise = []
	where  n = length k

-------symbol parser-------
symbol :: Eq s => s -> Parser s s
symbol a [] = []
symbol a (x:xs)
	|a==x = [(xs,x)]
	|otherwise = []

-------Combinators---------
infixr 6 <*>
infixr 5 <@
infixr 4 <|>
(<*>) :: Parser s r1 -> Parser s r2 -> Parser s (r1,r2)	--sequential
(p1 <*> p2) xs = [(xs2,(v1,v2))|(xs1,v1) <- p1 xs, (xs2,v2) <- p2 xs1]

(<|>) :: Parser s r -> Parser s r -> Parser s r		--alternate
(p1 <|> p2) xs = p1 xs ++ p2 xs

(<@) :: Parser s a -> (a->b) -> Parser s b
(p <@ f) xs = [(ys, f v)|(ys, v) <- p xs]

------Combine parsers-----
myCombine = symbol 'a' <|> symbol 'b'

---------epsilon----------
epsilon :: Parser symbol ()
epsilon xs = [(xs,())]

---------bracket grammar----
data Tree=Nil
          |Bin(Tree, Tree) deriving Show
parens :: Parser Char Tree
parens =(
	symbol 'a'
	<*>
	parens
	<*>
	symbol 'b'
	<*>
	parens
	)	<@ ( \(_, (x, (_, y))) -> Bin(x, y) )
	<|>
	epsilon <@ const Nil

-----------Yogi grammar----------------------
parens1 :: Parser Char Int
parens1 =(
	symbol 'a'
	<*>
        parens1) <@ (\(_,x) ->1+x )
	<|>
	(symbol 'b'
	<*>
	parens1) <@ (\(_,x) ->1+x )
	<|>
	succeed 0

parens2 xs=[head (parens1 xs)]

----------succeed-------------------------
succeed :: r -> Parser s r
succeed v xs = [(xs, v)]

---------other operators-----------------------
(<*) :: Parser s a -> Parser s b ->Parser s a
p <* q = p <*> q <@ fst
(*>) :: Parser s a -> Parser s b -> Parser s b
p *> q = p <*> q <@ snd

-----------brackets-----------------------
open = symbol '('
close = symbol ')'

parense :: Parser Char Tree
parense = (open *> parense <* close) <*> parense <@ Bin
	  <|> succeed Nil

--------------nesting----------------------
sp :: Parser Char a -> Parser Char a
sp p = p.dropWhile(==' ')

just :: Parser s a -> Parser s a
just p xs= [(x,y)|(x,y)<-p xs, null x]

nesting :: Parser Char Int
nesting = (open *> nesting <* close) <*> nesting <@ f
	  <|> succeed 0
  where f (x,y) = max (1+x) y  

------------More combinators-------
many :: Parser s a -> Parser s [a]
many p = p <*> many p	<@	(\(x,xs) -> x:xs)
	 <|> epsilon 	<@	(\_ -> [])
	 
-----------list of-----------------
list1 (x,xs) = x:xs
--(<:*>) :: Parser s a -> Parser s a -> Parser s [a]
p1 <:*> p2 = p1 <*> p2 <@ list1

many' p = p <:*> many' p <|> succeed []

listOf :: Parser s a -> Parser s b -> Parser s [a]
listOf p s = p <:*> many (s *> p) <|> succeed []
----------------Comma, semi---------
commaList, semicList :: Parser Char a -> Parser Char [a]
commaList p = listOf p (symbol ',')
semicList p = listOf p (symbol ';')

digit :: Parser Char Int
digit [] = []
digit (x:xs)
  | (read (x:[])::Int) `elem` [0..9] = [(xs,read (x:[])::Int)]
  | otherwise = []

natural :: Parser Char Int
natural = many digit <@ foldl f 0
  where f a b = a*10 + b
	
option :: Parser s a -> Parser s [a]
option p = p <@ (\x -> [x])
	<|> epsilon <@ (\x -> [])