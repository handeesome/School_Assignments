rotate :: Int -> [a] -> [a]
rotate x [] = []
rotate 0 list = list
rotate 1 list = tail list ++ [head list]
rotate x list = rotate (x-1) (tail list ++ [head list])
