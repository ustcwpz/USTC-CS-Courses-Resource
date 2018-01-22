-- CS242 Autumn 2009 - Homework 2, Problem 3
--
-- Type inference, program representations, and analysis of programs

-- PLEASE MAKE SURE YOUR CODE COMPILES PROPERLY AND CONTAINS ONLY THE
-- CHANGES THAT WE TOLD YOU TO MAKE.  WE WILL BE GRADING YOUR CODE
-- USING AUTOMATED SCRIPTS, SO IF IT DOESN'T COMPILE, THEN YOU WILL GET
-- ZERO POINTS.  OUR SCRIPTS CANNOT GRADE WHAT YOU WRITE IN COMMENTS, SO
-- PLEASE MAKE SURE TO UN-COMMENT ALL OF THE CODE YOU WANT US TO GRADE.

module Inference where
import qualified Data.Set as Set

-- uHaskell is a tiny subset of Haskell.  The data structures Id, Decl, Pat, and Exp together
-- define a parse tree representation of uHaskell programs.

-- Type of identifiers
type Id = String 

-- Type to represent declarations
-- Example: addPair (x,y) = x + y
-- The function name (Id) is being declared. 
data Decl = Fn Id Pat Exp
 deriving Show

-- Type to represent patterns
-- Examples: x, (x,y), x:xs
-- Variables in patterns are bound variables
data Pat = PatVar Id | PatPair Pat Pat | PatCons Pat Pat | PatNil
  deriving Show

-- Type to represent expressions.
-- First argument to LetExp is a bound variable
data Exp  = IntExp Int | BoolExp Bool | ExpVar Id | Cond Exp Exp Exp | Nil 
           | App Exp Exp | LetExp Pat Exp Exp 
 deriving Show

-- (a). Give a Haskell expression named myDecl of type Decl that represents the uHaskell program
--      f (x,y) = let z = 2 * x in z + y
-- Note that "*" and "+" should be treated as variables, since they are the names of functions.

myDecl = Fn "f" (PatPair (PatVar "x") (PatVar "y")) (LetExp (PatVar "z") (App (IntExp 2) (App (ExpVar "*") (ExpVar "x"))) (App (ExpVar "z") (App (ExpVar "+") (ExpVar "y"))))
-- [FILL IN DEFINITION]


-- (b). The function freeVars maps a declaration to the set of free variables in the declaration.
--      Fill in the missing pieces of the functions varsInPat and freeVarsE 
--      to complete the definition of freeVars

-- The Haskell library Data.Set, documented on the web 
-- (http://www.haskell.org/ghc/docs/latest/html/libraries/containers/Data-Set.html)
-- provides an implementation of sets.
-- The directive 'import qualified Data.Set as Set' at the top of this file provides access
-- to this library.  For example, Set.insert name S calls the Set insert function to insert
-- name into set S.
-- You might want to define an additional Haskell module Main in a file TestInfer.hs
-- that calls freeVars on various test cases.   For example:
--
-- module Main where
-- import Inference
-- ...
-- The command-line invocation:
--   ~> ghc --make TestInfer.hs 
--
-- will compile Main and Inference and put the result in an executable TestInfer.

-- This function won't work until varsInPat and freeVarsE have been
-- completed by you
freeVars :: Decl -> Set.Set Id
freeVars decl = case decl of 
  Fn name pat exp -> let
     boundVars = Set.insert name (varsInPat pat)
     in Set.difference (freeVarsE exp) boundVars

varsInPat :: Pat -> Set.Set Id
varsInPat pat = case pat of
  PatVar var -> Set.singleton var
  PatPair pat1 pat2 -> Set.unions [(varsInPat pat1), (varsInPat pat2)]
  PatCons pat1 pat2 -> Set.unions [(varsInPat pat1), (varsInPat pat2)]
  PatNil -> Set.empty
-- [FILL IN FUNCTION BODY]
  
freeVarsE :: Exp -> Set.Set Id
freeVarsE x = case x of
  IntExp i -> Set.empty
  BoolExp b -> Set.empty
-- [FILL IN SOME OF THE FUNCTION BODY]
  ExpVar id -> Set.singleton id
  Cond exp1 exp2 exp3 -> Set.unions [(freeVarsE exp1), (freeVarsE exp2), (freeVarsE exp3)]
  Nil -> Set.empty
  App exp1 exp2 -> Set.unions [(freeVarsE exp1), (freeVarsE exp2)]
  LetExp pat exp1 exp2 -> Set.difference (Set.unions [(freeVarsE exp1), (freeVarsE exp2)]) (varsInPat pat)
-- [FILL IN MORE OF THE FUNCTION BODY]


-- DO NOT define your own main() function when you turn in this
-- assignment, because it interferes with the main() in the test program