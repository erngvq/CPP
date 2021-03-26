## Dynamic Programming (Memoization & Tabulation)

* Write a function `fib(n)` that takes in a number as an argument. The function should return the n-th number of the Fibonacci sequence. Recall that the first and second number of the sequence is 1, and to generate the next number we sum the previous two.

* Imagine you are a traveler on a 2D grid. You begin in the top-left corner and your goal is to travel to the bottom-right corner. However, you many only move down or right. Write a function `gridTraveler(m, n)` that computes how many ways you can travel to the goal on a grid with dimensions `m * n`.

* Write a function `canSum(target, numbers)` that returns a boolean indicating whether or not it is possible to generate the target using the number from the array. An element from the array many be used as many times as needed, and assume all input numbers are non-negative.

* Write a function `howSum(target, numbers)` that returns an array containing ANY combination of elements that add up to exactly the target integer. If there is no combination that adds up to the target, return null.

* Write a function `bestSum(target, numbers)` that returns an array containing the SHORTEST combination of numbers that add up to exactly the target integer. If there is a tie for the shortest combination, return any of them.

* Write a function `canConstruct(target, wordBank)` that accepts a target string and an array of strings. The function should return a boolean indicating whether or not the target can be constructed by concatenating elements of the word bank array. Elements from the word bank may be reused as many times as needed.

* Write a function `canConstruct(target, wordBank)` that returns the number of ways that the target can be constructed by concatenating elements of the word bank array. As before, elements from the word bank may be reused as many times as needed.

* Write a function `allConstruct(target, wordBank)` that returns a 2D array containing all the ways that the target can be constructed by concatenating elements of the word bank array. Each element of the 2D array should represent one combination that constructs the target. As before, elements from the word bank may be reused as many times as needed.

* Given an integer array representing coins of different denominations and an integer representing a total amount of money, write a function `coinChange(coins, amount)` that return the fewest number of coins that you need to make up that amount. Assume that there is an infinite number of each kind of coin; however, if the amount of money specified cannot be made up by any combination of the coins, return -1.
