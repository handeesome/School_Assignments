    isPrime :: Int -> Bool
    isPrime x = one x 2
    
    one :: Int -> Int -> Bool
    one x y
     | x == 1 = False
     | x == 2 = True
     | y == x `div`2 = True
     | x `mod` y /= 0 = one x (y+1)
     | x `mod` y == 0 = False

    
    