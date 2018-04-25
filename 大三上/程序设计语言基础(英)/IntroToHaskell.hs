{- ghci command
    Start ghci:
    prompt>ghci      -- or -- prompt> ghci intro.hs
    
    Prelude>:load IntroToHaskell.hs     -- load the definitions in IntroToHaskell.hs
    Prelude>:r                          -- reload the previous file.
    
    Prelude> :set +t                    -- asks for more type information to be displayed.
-}
module Main where
import Data.List         -- It should work just inporting List, but...
import Test.QuickCheck   -- used for doing random testing of code

l = [1,2,3]
r = foldl (\accumulator i -> i + accumulator) 0 l


{-  We can type expressions directly into ghci:
(5+3) - 2
if 5>3 then "Harry" else "Hermione"
5 == 4
-}

-- Overview by Type
-- Base Types
-- Bool
true = True
false = False

ifExpression = if true then 10 else 13

-- Integers
anInt = 2
anIntExpression = 2 * 4

-- Strings (note, String = [Char])
aString :: String           --  "::" means "has type"
aString = "Ron Weasley"

-- Real numbers
aFloat = 2.2

-- Simple compound types
-- Tuples
aTuple = (4,5,"Griffendor")

-- Lists
nilList :: [a]             -- Lowercase types are type variables.
nilList = []               -- polymorphic type

anIntList = 1 : [2,3,4]    -- Infix cons notation (:)   
                           -- Note, ML uses :: for cons and : for "has type".

-- Records
data Person = Person {firstName :: String, lastName :: String}
  deriving Show
hg = Person {firstName = "Hermione", lastName = "Granger"}

-- Patterns and Declarations
-- Patterns can be used in place of variables
-- <pat> ::= <var> | <tuple> | <cons> | <record>
--
-- Value declarations
-- <pat = <exp>

myTuple = ("Flitwick", "Snape")
(x,y) = myTuple

myList = [1,2,3,4]
z:zs = myList

-- Let allows us to introduce local declarations
localDecl = let (x,y) = (2,"Snape") in x * 4 

-- Functions and Pattern Matching
anonymousFunction = \x -> x + 1      -- Like Lisp lambda, function (...) in Javascript

-- Declaration form:
-- <name> <pat1> = <exp1>
-- <name> <pat2> = <exp2>
-- <name> <pat3> = <exp3>

-- Single-branch function defined using tuple pattern as argument.
f (x,y) = x + y

-- Curried version of f
g x y = x + y

-- Multiple-branch function defined using list pattern as argument.
myLength [] = 0
myLength (x:xs) = 1 + myLength xs


-- Map function on Lists
myMap f [] = []
myMap f (x:xs) = f x : myMap f xs

applyMap = myMap (\x -> x + 1) [1,2,3]

-- More functions on lists.
append([], ys) = ys
append(x:xs, ys) = x : append(xs, ys)

myReverse [] = []
myReverse (x:xs) =  (reverse xs) ++ [x] 

-- How efficient is reverse?










-- This pattern of writing a related function with an extra "accumulator" 
-- is very common in functional programming.
accumReverse xs =
    let rev ( [], z ) = z
        rev ( y:ys, z ) = rev( ys, y:z )
    in rev( xs, [] )

-- List Comprehensions
myData = [1,2,3,4,5,6,7]
twiceData = [2 * x | x <- myData]
twiceEvenData = [2*x| x <- myData, x `mod` 2 == 0]


-- Datatype declarations
-- Type Names and data constructors start with capital letters.
data Color = Red | Yellow | Blue        -- Elements of type Color are Red, Yellow, and Blue
   deriving Show


-- Data constructors can take arguments
data Atom = Atom String | Number Int   
 deriving Show
atom1 = Atom "oxygen"
atom2 = Number 8


-- Data declarations can be recursive.
data List = Nil | Cons  (Atom,List)
list1 = Nil
list2 = Cons (atom1, list1)


-- Data declarations can be parameterized by type variables
data Tree a = Leaf a | Node (a, Tree a, Tree a)
            deriving Show

aTree = Node(4, Node(3, Leaf 1, Leaf 2),
                Node(5, Leaf 6, Leaf 7))         

-- Functions over datatypes use pattern matching over data constructors to access values:
tsum (Leaf n) = n
tsum (Node(n,t1,t2)) = n + tsum(t1) + tsum(t2)


-- Example: Evaluating Expressions
-- Define datatype of expressions:
data Exp = Var String | Const Int | Plus (Exp, Exp)
           deriving Show

-- exampleExp is (x + 3) + y
exampleExp =  Plus(Plus(Var "x", Const 3), Var "y")

-- We can also use a case expression to deconstruct values of a datatype:
-- Indentation matters in branches of a case in Haskell.  
-- All branches must start at the same column.
exampleCase = case exampleExp of
               Var n ->  0
               Const n -> 0
               Plus(e1,e2) -> 2 

-- Suppose we want to write an evaluation function to simplify our expressions
exampleExp2 = Plus(Const 3, Const 2)                 -- Const 5
exampleExp3 = Plus(Var "x", Plus(Const 2, Const 3))  -- Plus (Var "x", Const 5)

exampleExp4 = Plus(Var "x", Plus(Const 2, Plus (Const 3, Const 4))) 


-- Definition of evaluation function:
ev ( Var s) = Var s
ev ( Const n ) = Const n
ev ( Plus ( e1,e2 ) ) = 
     case ev e1 of
          Var s -> Plus( Var s, ev e2)      
          Const n -> case ev e2 of  
                              Var s -> Plus(Const n, Var s)      
                              Const m -> Const (n+m)                         
                              Plus(e3,e4) -> Plus ( Const n, Plus ( e3, e4 ))   
          Plus(e3, e4) -> Plus( Plus ( e3, e4 ), ev e2)

-- Laziness
-- Haskell is lazy language.
-- Functions and data constructors don't evaulate their arguments until they need them.


-- Programmers can write their own control-flow operators:
cond :: Bool -> a -> a -> a 
cond True  t e = t
cond False t e = e


-- Why can't programmers write such operations in eager languages?


-- Using laziness
-- "Harry" `isSubString` "Harry Potter"
-- (Putting ticks around a function makes it an infix operator.)
-- (Putting parens around an infix operator makes it a normal function: (+) 3 2 evaulates to 5)
isSubString :: String -> String -> Bool
x `isSubString` s = or [ x `isPrefixOf` t | t <- suffixes s ]

suffixes :: String -> [String]
-- All suffixes of s
suffixes []     = [""]
suffixes (x:xs) = (x:xs) : suffixes xs



-- Another example
-- (or bs) returns True if any of the bs is True
myOr :: [Bool] -> Bool
myOr []     = False
myOr (b:bs) = b || myOr bs



-- Infinte data structures
-- Laziness allows us to use conceptually infinte data structures.  Because values
-- are only computed when they are needed, the infinite structure is not materialized
-- (unless the code is looping infinitely..)

-- The haskell notation [n..] generates the infinite sequence of natural numbers starting at n

naturals = [0..]

-- The function 'take n list' returns the first n elements of the list 'list', so 
-- first10 is the list [0,1,2,3,4,5,6,7,8,9]
first10 = take 10 naturals


-- primesN is the infite list of primes.
-- It is defined using list comprehension notation.
primesN :: [Int]
primesN = let
    sieve(p:xs) = p : sieve [ x | x <- xs, x `mod` p > 0]
      in sieve [2..]


-- A lazy paradigm
-- Generate all solutions (a potentially enormous tree)
-- Walk the tree to find the solution you want

nextMove :: Board -> Move
nextMove b = selectMove allMoves
  where allMoves = allMovesFrom b

data Board = Board  -- Put real definition here
data Move = Move    -- Put real definition here
selectMove moves = undefined   -- undefined is Haskell function that runs for ever, has type a
allMovesFrom b =   undefined   -- replace with real definition



-- Testing
-- It is good to write tests as you write code.
-- Printf-style debugging doesn't work in Haskell.  Why?
-- You can use ghci as an interactive shell to test code as you write it.

-- The QuickCheck library helps with testing by generating random test data
-- automatically from the type of the function being tested.
-- Consider the function 'eReverse' that reverses a list using an accumulator:
eReverse xs =
    let rev ( [], z ) = []
        rev ( y:ys, z ) = rev( ys, y:z )
    in rev( xs, [] )

-- Define a non-polymorphic type at which to test the function
type TS =  [Int] 

-- Define property we wish to test:
prop_RevRev :: TS -> Bool
prop_RevRev l = eReverse (eReverse l) == l

-- Run in ghci
test_result= quickCheck prop_RevRev

-- We can fix the function and rerun property checker.
-- Note that quickCheck is a Haskell ** library **.  There is no special interaction
-- with ghc or ghci
 
-- This file can also be compiled, using ghc --make IntroToHaskell.hs
main =  
  putStrLn "Code snippets from lecture on an Introduction to Haskell.  Use ghci IntroToHaskell.hs to play with snippets."