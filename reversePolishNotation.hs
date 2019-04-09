import Data.List  
  
rPN :: String -> Float  
rPN = head . foldl rpnFx [] . words  
    where   rpnFx (x:y:ys) "*" = (x * y):ys  
            rpnFx (x:y:ys) "+" = (x + y):ys  
            rpnFx (x:y:ys) "-" = (y - x):ys  
            rpnFx (x:y:ys) "/" = (y / x):ys  
            rpnFx (x:y:ys) "^" = (y ** x):ys  
            rpnFx (x:xs) "ln" = log x:xs  
            rpnFx xs "sum" = [sum xs]  
            rpnFx xs numberString = read numberString:xs  