data Term = Con Int | Div Term Term
eval :: Term -> Int
eval(Con a) = a
eval(Div t u) = eval t `div` eval u
answer , error :: Term

answer = (Div (Div (Con 1972) (Con 2))(Con 23))
error = Div (Con 1) (Con 0)

(x, y) = 1 2

--c = 1
(c, d) = ( (), 2)