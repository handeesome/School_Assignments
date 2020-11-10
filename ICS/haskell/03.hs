isPrime :: Int -> Bool
isPrime x = one x 2

one :: Int -> Int -> Bool
one x y
 | x == 1 = False
 | x == 2 = True
 | y == x `div`2 = True
 | x `mod` y /= 0 = one x (y+1)
 | x `mod` y == 0 = False

rotate :: Int -> [a] -> [a]
rotate x [] = []
rotate 0 list = list
rotate 1 list = tail list ++ [head list]
rotate x list = rotate (x-1) (tail list ++ [head list])

show :: Show a => a -> String
read :: Read a => String -> a
isCircPrime :: Integer -> Bool
isCircPrime x
 | a == length (show x) = True
 | isPrime x == True = isCircPrime (read (rotate (a+1) (show x) ) :: Integer)
 | isPrime x == False = False
 where a = 0