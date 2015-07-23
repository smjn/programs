funcWithCapLetter = "Func with cap letter"  --definition
-----------------------X----------------------
ifElseTest x = if x > 5 then x+1 else x+2   --expression
-----------------------X----------------------
squares = [f x | x <- [1..10]] where f x = x*x
----------------------X-----------------------
length' xs = sum [1 | _ <- xs]
-----------------------X---------------------
removeNonUppercase xs = [c|c<-xs,c `elem` ['A'..'Z']]