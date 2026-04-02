# 2718. Sum of Matrix After Queries

**Difficulty:** Medium

**Topics:** Array, Hash Table

**Link:** https://leetcode.com/problems/sum-of-matrix-after-queries/

---

## Description

You are given an integer n and a 0-indexed 2D array queries where queries[i] = [type_i, index_i, val_i].

Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:

	
• if type_i == 0, set the values in the row with index_i to val_i, overwriting any previous values.
	
• if type_i == 1, set the values in the column with index_i to val_i, overwriting any previous values.

Return the sum of integers in the matrix after all queries are applied.

 

Example 1:

Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
Output: 23
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 

Example 2:

Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
Output: 17
Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.

 

Constraints:

	
• 1 <= n <= 10^4
	
• 1 <= queries.length <= 5 * 10^4
	
• queries[i].length == 3
	
• 0 <= type_i <= 1
	
• 0 <= index_i < n
	
• 0 <= val_i <= 10^5

---

## Hints

- Hint 1: Process queries in reversed order, as the latest queries represent the most recent changes in the matrix.
- Hint 2: Once you encounter an operation on some row/column, no further operations will affect the values in this row/column. Keep track of seen rows and columns with a set.
- Hint 3: When operating on an unseen row/column, the number of affected cells is the number of columns/rows you haven’t previously seen.
