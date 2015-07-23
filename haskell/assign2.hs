type Fname = String
type Var = String
data Program = Prog [Fundef] Exp deriving Show
data Fundef = Fun String [String] Exp deriving Show
data Exp = I Int | V Var | B Bool | Nil | Fname String | App Exp Exp deriving Show

type Code = [Instn]

data Instn = 
    PUSH Int
    | PUSHINT Int
    | PUSHGLOBAL String
    | PUSHBOOL Bool
    | PUSHNIL
    | POP Int
    | EVAL
    | UNWIND
    | MKAP
    | UPDATE Int
    | RETURN
    | LABEL String
    | JUMP String
    | JFALSE String
    | ADD
    | SUB
    | MUL
    | DIV
    | CONS
    | HEAD
    | TAIL
    | IF
    | EQU
    | GLOBSTART String Int
    | PRINT
    | STOP

instance Show Instn where
    show (PUSH i) = "PUSH " ++ show i ++ "\n"
    show (PUSHINT i) = "PUSHINT " ++ show i ++ "\n"
    show (PUSHGLOBAL str) = "PUSHGLOBAL " ++ show str ++ "\n"
    show (PUSHBOOL b) = "PUSHBOOL " ++ show b ++ "\n"
    show PUSHNIL = "PUSHNIL " ++ "\n"
    show (POP i) = "POP " ++ show i ++ "\n"
    show EVAL = "EVAL" ++ "\n"
    show UNWIND = "UNWIND" ++ "\n"
    show MKAP = "MKAP" ++ "\n"
    show RETURN = "RETURN" ++ "\n"
    show (UPDATE i) = "UPDATE " ++ show i ++ "\n"
    show (LABEL str) = "LABEL " ++ show str ++ "\n"
    show (JUMP str) = "JUMP " ++ show str ++ "\n"
    show (JFALSE str) = "JFALSE " ++ show str ++ "\n"
    show ADD = "ADD" ++ "\n"
    show SUB = "SUB" ++ "\n"
    show MUL = "MUL" ++ "\n"
    show DIV = "DIV" ++ "\n"
    show CONS = "CONS" ++ "\n"
    show HEAD = "HEAD" ++ "\n"
    show TAIL = "TAIL" ++ "\n"
    show IF = "IF" ++ "\n"
    show EQU = "EQU" ++ "\n"
    show (GLOBSTART str i) = "\n GLOBSTART " ++ show str ++ " " ++ show i ++ "\n"
    show PRINT = "PRINT" ++ "\n"
    show STOP = "STOP" ++ "\n"

start (Prog fdefList term) = (foldr func g fdefList)
    where
        g = LABEL "MAIN":(expr term (\x -> 999) 999) (EVAL:PRINT:STOP:hardCoded) --here the 999 are arbitrary

hardCoded = concat (map (getCode) builtins)

func (Fun fname argList fdef) codeTillNow = GLOBSTART fname n:(body fdef r n codeTillNow)
    where
        n = length argList
        tupleList = foldr (\x acc -> (x, (length acc)+1):acc) [] argList
        r ident = snd$head (filter (\(v,x) -> v==ident) tupleList)

body fbody r d codeTillNow= expr fbody r d ((UPDATE (d+1)):POP d:UNWIND:codeTillNow)

builtins = [("+",ADD), ("-",SUB), ("*",MUL), ("/",DIV), ("cons",CONS), ("head",HEAD), ("car",HEAD), ("cdr",HEAD), ("==",EQU), ("null",HEAD), ("if",IF)]

expr (I x) r d codeTillNow = PUSHINT x:codeTillNow

expr (B x) r d codeTillNow = PUSHBOOL x:codeTillNow

expr (Fname fname) _ _ codeTillNow = PUSHGLOBAL fname:codeTillNow

expr (V v) r d codeTillNow = PUSH (d - (r v)):codeTillNow

expr (App (x) (y)) r d codeTillNow = expr (y) r d (expr (x) r (d+1) (MKAP:codeTillNow))

expr (Nil) r d codeTillNow = PUSHNIL:codeTillNow

getCode (mini,gcode)
    |(mini `elem` ["+","-","*","/","=="]) = [GLOBSTART mini 2, PUSH 1, EVAL, PUSH 1, EVAL, gcode, UPDATE 3]
    |(mini=="cons") = [GLOBSTART mini 1, gcode, UPDATE 1, RETURN]
    |(mini `elem` ["head","car","cdr","null"]) = [GLOBSTART mini 1, EVAL, gcode, EVAL, UPDATE 1, UNWIND]
    |(mini=="if") = [GLOBSTART mini 3, PUSH 0, EVAL, JFALSE "l1", PUSH 1, JUMP "l2", LABEL "l1", PUSH 2, LABEL "l2", EVAL, UPDATE 4, POP 3, UNWIND]
    |otherwise = []

gencpgm :: Program -> Code
gencpgm p = start p
