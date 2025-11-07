myremoveduplicates :: Eq a => [a] -> [a]
myremoveduplicates input_list
    | null input_list                                       = []
    | elem (head input_list) (tail input_list)              = myremoveduplicates (tail input_list)
    | otherwise                                             = (head input_list):(myremoveduplicates (tail input_list))


myremoveduplicates_pm :: Eq a => [a] -> [a]
myremoveduplicates_pm [] = []
myremoveduplicates_pm (x:xs) 
    | elem x xs     = myremoveduplicates_pm xs
    | otherwise     = x:(myremoveduplicates_pm xs)


myintersection :: Eq a => [a] -> [a] -> [a]
myintersection input_list_1 input_list_2
    | null input_list_1 = []
    | elem (head input_list_1) input_list_2 = (head input_list_1):(myintersection (tail input_list_1) input_list_2)
    | otherwise = myintersection (tail input_list_1) input_list_2


myintersection_pm :: Eq a => [a] -> [a] -> [a]
myintersection_pm [] input_list_2 = []
myintersection_pm (x:xs) input_list_2
    | elem x input_list_2 = x:(myintersection_pm xs input_list_2)
    | otherwise = myintersection_pm xs input_list_2


mynthtail :: Eq a => Int -> [a] -> [a]
mynthtail cut_num input_list
    | cut_num == 0      = input_list
    | otherwise         = mynthtail (cut_num - 1) (tail input_list)


mynthtail_pm :: Eq a => Int -> [a] -> [a]
mynthtail_pm 0 input_list = input_list
mynthtail_pm cut_num (x:xs) = mynthtail_pm (cut_num - 1) xs 


mylast :: Eq a => [a] -> [a]
mylast input_list
    | null input_list                           = input_list
    | null (tail input_list)                    = (head input_list):[]
    | otherwise                                 = mylast (tail input_list)


mylast_pm :: Eq a => [a] -> [a]
mylast_pm [] = []
mylast_pm (x:[]) = x:[]
mylast_pm (x:xs) = mylast_pm xs


myreverse :: Eq a => [a] -> [a]
myreverse input_list = myreverse_helper input_list []

myreverse_helper :: Eq a => [a] -> [a] -> [a]
myreverse_helper input_list result_list
    | null input_list                               = result_list
    | otherwise                                     = myreverse_helper (tail input_list) ((head input_list):result_list)


myreverse_pm :: Eq a => [a] -> [a]
myreverse_pm input_list = myreverse_pm_helper input_list []

myreverse_pm_helper :: Eq a => [a] -> [a] -> [a]
myreverse_pm_helper [] result_list = result_list
myreverse_pm_helper (x:xs) result_list = myreverse_pm_helper xs (x:result_list)


myreplaceall :: Eq a => a -> a -> [a] -> [a]
myreplaceall new_val old_val input_list
    | null input_list       = input_list
    | (head input_list) == old_val      = new_val:(myreplaceall new_val old_val (tail input_list))
    | otherwise = (head input_list):(myreplaceall new_val old_val (tail input_list))


myreplaceall_pm :: Eq a => a -> a -> [a] -> [a]
myreplaceall_pm new_val old_val [] = []
myreplaceall_pm new_val old_val (x:xs)
    | x == old_val = new_val:(myreplaceall_pm new_val old_val xs)
    | otherwise = x:(myreplaceall_pm new_val old_val xs)


myordered :: Ord a => [a] -> Bool
myordered input_list 
    | null input_list = True
    | null (tail input_list) = True
    | (head input_list) <= (head (tail input_list)) = myordered (tail input_list)
    | otherwise = False


myordered_pm :: Ord a => [a] -> Bool
myordered_pm [] = True
myordered_pm (x:[]) = True
myordered_pm (x:y:xs)
    | x <= y = myordered_pm (y:xs)
    | otherwise = False


-- Note: Used stack overflow for split function; needed help splitting string into list of strings on ';'; it benefitted me; I don't think harms my understanding
computeFees :: String -> Int
computeFees input_string = student (split ';' input_string)

split :: Char -> String -> [String]
split delim input_string
    | null input_string     = []
    | otherwise             = x:(split delim (drop 1 y)) where (x, y) = (span (/= delim) input_string)

c :: String -> Int
c input_string = convert_helper input_string 0

convert_helper :: String -> Int -> Int
convert_helper input_string result
    | null input_string         = result
    | head input_string == '0'  = convert_helper (tail input_string) (10 * result)
    | head input_string == '1'  = convert_helper (tail input_string) (10 * result + 1)
    | head input_string == '2'  = convert_helper (tail input_string) (10 * result + 2)
    | head input_string == '3'  = convert_helper (tail input_string) (10 * result + 3)
    | head input_string == '4'  = convert_helper (tail input_string) (10 * result + 4)
    | head input_string == '5'  = convert_helper (tail input_string) (10 * result + 5)
    | head input_string == '6'  = convert_helper (tail input_string) (10 * result + 6)
    | head input_string == '7'  = convert_helper (tail input_string) (10 * result + 7)
    | head input_string == '8'  = convert_helper (tail input_string) (10 * result + 8)
    | head input_string == '9'  = convert_helper (tail input_string) (10 * result + 9)

student :: [String] -> Int
student input_list
    | input_list!!5 == "Y"  = dsstudent input_list
    | otherwise             = ndsstudent input_list

dsstudent :: [String] -> Int
dsstudent input_list
    | input_list!!8 == "Y"  = finassist input_list
    | otherwise             = nofinassist input_list

finassist :: [String] -> Int
finassist input_list
    | ((c (input_list!!4)) < 12) && (100 + 50 + (c (input_list!!4)) * 275 - (c (input_list!!9)) > 0)    = 100 + 50 + 275 * (c (input_list!!4)) - (c (input_list!!9))
    | ((c (input_list!!4)) < 12) && (100 + 50 + (c (input_list!!4)) * 275 - (c (input_list!!9)) < 0)    = 0
    | ((c (input_list!!4)) >= 12) && (100 + 50 + 12 * 275 - (c (input_list!!9)) > 0)                    = 100 + 50 + 275 * 12 - (c (input_list!!9))
    | otherwise                                                                                         = 0

nofinassist :: [String] -> Int
nofinassist input_list
    | ((c (input_list!!4)) < 12)    = 100 + 50 + 275 * (c (input_list!!4))
    | otherwise                     = 100 + 50 + 275 * 12

ndsstudent :: [String] -> Int
ndsstudent input_list
    | input_list!!6 == "S"  = senior input_list
    | otherwise             = certificate input_list

senior :: [String] -> Int
senior input_list
    | (c (input_list!!4)) > 6   = 100 + ((c (input_list!!4)) - 6) * 50
    | otherwise                 = 100

certificate :: [String] -> Int
certificate input_list = 700 + (c (input_list!!4)) * 300