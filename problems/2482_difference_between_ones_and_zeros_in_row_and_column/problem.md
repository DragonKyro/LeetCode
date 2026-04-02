# 2482. Difference Between Ones and Zeros in Row and Column

**Difficulty:** Medium

**Topics:** Array, Matrix, Simulation

**Link:** https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

---

## Description

You are given a 0-indexed m x n binary matrix grid.

A 0-indexed m x n difference matrix diff is created with the following procedure:

	
• Let the number of ones in the i^th row be onesRow_i.
	
• Let the number of ones in the j^th column be onesCol_j.
	
• Let the number of zeros in the i^th row be zerosRow_i.
	
• Let the number of zeros in the j^th column be zerosCol_j.
	
• diff[i][j] = onesRow_i + onesCol_j - zerosRow_i - zerosCol_j

Return the difference matrix diff.

 

Example 1:

Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
Explanation:
- diff[0][0] = onesRow_0 + onesCol_0 - zerosRow_0 - zerosCol_0 = 2 + 1 - 1 - 2 = 0 
- diff[0][1] = onesRow_0 + onesCol_1 - zerosRow_0 - zerosCol_1 = 2 + 1 - 1 - 2 = 0 
- diff[0][2] = onesRow_0 + onesCol_2 - zerosRow_0 - zerosCol_2 = 2 + 3 - 1 - 0 = 4 
- diff[1][0] = onesRow_1 + onesCol_0 - zerosRow_1 - zerosCol_0 = 2 + 1 - 1 - 2 = 0 
- diff[1][1] = onesRow_1 + onesCol_1 - zerosRow_1 - zerosCol_1 = 2 + 1 - 1 - 2 = 0 
- diff[1][2] = onesRow_1 + onesCol_2 - zerosRow_1 - zerosCol_2 = 2 + 3 - 1 - 0 = 4 
- diff[2][0] = onesRow_2 + onesCol_0 - zerosRow_2 - zerosCol_0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow_2 + onesCol_1 - zerosRow_2 - zerosCol_1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow_2 + onesCol_2 - zerosRow_2 - zerosCol_2 = 1 + 3 - 2 - 0 = 2

Example 2:

Input: grid = [[1,1,1],[1,1,1]]
Output: [[5,5,5],[5,5,5]]
Explanation:
- diff[0][0] = onesRow_0 + onesCol_0 - zerosRow_0 - zerosCol_0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow_0 + onesCol_1 - zerosRow_0 - zerosCol_1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow_0 + onesCol_2 - zerosRow_0 - zerosCol_2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow_1 + onesCol_0 - zerosRow_1 - zerosCol_0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow_1 + onesCol_1 - zerosRow_1 - zerosCol_1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow_1 + onesCol_2 - zerosRow_1 - zerosCol_2 = 3 + 2 - 0 - 0 = 5

 

Constraints:

	
• m == grid.length
	
• n == grid[i].length
	
• 1 <= m, n <= 10^5
	
• 1 <= m * n <= 10^5
	
• grid[i][j] is either 0 or 1.

---

## Hints

- Hint 1: You need to reuse information about a row or a column many times. Try storing it to avoid computing it multiple times.
- Hint 2: Use an array to store the number of 1’s in each row and another array to store the number of 1’s in each column. Once you know the number of 1’s in each row or column, you can also easily calculate the number of 0’s.
