    isPrime :: Int -> Bool
    isPrime x = one x 2

    isSpecialPrime :: Integer -> Bool
    isSpecialPrime x = isPrime zipWith(+)(filter isPrime[1..x])(filter isPrime[3..x])
    
    one :: Int -> Int -> Bool
    one x y
     | x == 1 = False
     | x == 2 = True
     | y == x `div`2 = True
     | x `mod` y /= 0 = one x (y+1)
     | x `mod` y == 0 = False

    
    