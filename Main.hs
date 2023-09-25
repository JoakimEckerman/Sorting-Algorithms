module Main where

import Data.List
import Data.Ord

data Person = Person {name :: String, age :: Int} deriving (Show, Eq)

sortByName :: [Person] -> [Person]
sortByName = sortOn name

sortByAge :: [Person] -> [Person]
sortByAge = sortOn age

length1 [] = 0
length1 (a : as) = 1 + length as

numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]

people = [Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19, Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23, Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, Person "Juan" 33, Person "Natalie" 25]

main :: IO ()
main = do
  let a = sort numbers
  print "Numbers:"
  print a
  print "People by name:"
  let b = sortByName people
  print b
  print "People by descending age:"
  let c = sortByAge people
  let d = reverse c
  print d