import Data.Char

toAnimal :: Char -> Char
toAnimal c = chr . (+127970) $ ord c

toSmileyEmoji :: Char-> Char
toSmileyEmoji c = chr . (+128415) $ ord c

encode :: String -> String
encode xs = map (\c -> if isUpper c then (chr . (+127970) $ ord c) else (chr . (+128415) $ ord c)) xs

fromAnimal :: Char -> Char
fromAnimal c = chr $ (ord c) - 127970

fromSmileyEmoji :: Char-> Char
fromSmileyEmoji c = chr $ (ord c) - 128415

isAnimal :: Char -> Bool
isAnimal c = if ((ord c >= ord '🐣') && (ord c <= ord '🐼')) then True else False

decode :: String -> String
decode xs = map (\c -> if isAnimal c then (chr $ (ord c) - 127970) else (chr $ (ord c) - 128415)) xs

-- Peek into the content to decide whether we encode or decode.
convert :: String -> String
convert xs
 | null $ filter (\c -> isLetter c && isAscii c) xs = decode xs
 | otherwise = encode xs   

