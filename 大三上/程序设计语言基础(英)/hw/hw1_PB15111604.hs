--HW1 for FoPL
--Stu:金泽文 No:PB15111604

-----------------------------------------------
--4
--(a)
data Tree a = Leaf a | Node (Tree a) (Tree a)
maptree f (Leaf a) = Leaf (f a)
maptree f (Node x y) = Node (maptree f x) (maptree f y)
--(b)
--maptree的第一个参数是函数f：函数f的参数是Tree a，f返回某b，故maptree参数及返回值类型如此。定义maptree时使用递归，边界条件是第二个参数时(Leaf a)时，这里用了pattern matching；递归时分别递归到子树x y并用Node连接。
--(c)
--ghci给的是maptree :: (t -> a) -> Tree t -> Tree a        而(t -> t) -> Tree t -> Tree t中f函数返回值类型与参数类型一致。我猜测是因为从maptree的定义里无法推断出f函数的返回值类型与参数类型一致，可能会根据f函数实际的不同而导致类型的偏差。



-----------------------------------------------
--5
--(a)
reduce :: (a -> a -> a) -> Tree a -> a
reduce op (Leaf x) = x
reduce op (Node x y) = op (reduce op x) (reduce op y)

--(b)
--边界条件是最后一个参数为Leaf x时，这时应该返回x本身，递归时每个Node应该op两个左右子树，即 (reduce op x)以及(reduce op y)



-----------------------------------------------
--6
--(a)
currya :: ((a,b) -> c) -> (a -> (b -> c))
currya f = \x y -> f (x,y)

uncurrya :: (a -> (b -> c)) -> ((a,b) -> c)
uncurrya f = \(x,y) -> f x y
--(为了不与标准curry，uncurry冲突，在我定义的样例分别加了后缀a)
--(b)
--首先，类型(a->(b->c))与(a->b->c)是identical。其次，先curry f x y 得到 f (x,y)，再由uncurry f(x,y)得到f x y，自然与原来等价。先uncurry再curry类似。



-----------------------------------------------
--7
--(a)
evens = [2,4..]
odds = [1,3..]

--(b)
merge :: [Int] -> [Int] -> [Int]
merge a [] = a
merge [] a = a
merge (a:as) (b:bs) 
    | a < b = a : merge as (b:bs)
    | otherwise = b : merge (a:as) bs

--(c)
--在一定的测量范围内不终止。
--1.因为odds 和evens都是infinite lists。
--2.为什么说“一定的测量范围”？因为老师上课讲过，是否会终止我们不能证明“不终止”，因为过长的时间脱离实际。
--3.经过一段时间的执行与测量，发现ghci执行期间内存稳定，并无明显变化，并且也没有遇到溢出情况


-----------------------------------------------
