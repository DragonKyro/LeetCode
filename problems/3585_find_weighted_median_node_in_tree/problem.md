# 3585. Find Weighted Median Node in Tree

**Difficulty:** Hard

**Topics:** Array, Binary Search, Dynamic Programming, Bit Manipulation, Tree, Depth-First Search

**Link:** https://leetcode.com/problems/find-weighted-median-node-in-tree/

---

## Description

You are given an integer n and an undirected, weighted tree rooted at node 0 with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [u_i, v_i, w_i] indicates an edge from node u_i to v_i with weight w_i.

The weighted median node is defined as the first node x on the path from u_i to v_i such that the sum of edge weights from u_i to x is greater than or equal to half of the total path weight.

You are given a 2D integer array queries. For each queries[j] = [u_j, v_j], determine the weighted median node along the path from u_j to v_j.

Return an array ans, where ans[j] is the node index of the weighted median for queries[j].

 

Example 1:

Input: n = 2, edges = [[0,1,7]], queries = [[1,0],[0,1]]

Output: [0,1]

Explanation:

	
		
			Query
			Path
			Edge

			Weights
			Total

			Path

			Weight
			Half
			Explanation
			Answer
		
	
	
		
			[1, 0]
			1 → 0
			[7]
			7
			3.5
			Sum from 1 → 0 = 7 >= 3.5, median is node 0.
			0
		
		
			[0, 1]
			0 → 1
			[7]
			7
			3.5
			Sum from 0 → 1 = 7 >= 3.5, median is node 1.
			1
		
	

Example 2:

Input: n = 3, edges = [[0,1,2],[2,0,4]], queries = [[0,1],[2,0],[1,2]]

Output: [1,0,2]

Explanation:

	
		
			Query
			Path
			Edge

			Weights
			Total

			Path

			Weight
			Half
			Explanation
			Answer
		
	
	
		
			[0, 1]
			0 → 1
			[2]
			2
			1
			Sum from 0 → 1 = 2 >= 1, median is node 1.
			1
		
		
			[2, 0]
			2 → 0
			[4]
			4
			2
			Sum from 2 → 0 = 4 >= 2, median is node 0.
			0
		
		
			[1, 2]
			1 → 0 → 2
			[2, 4]
			6
			3
			Sum from 1 → 0 = 2 < 3.

			Sum from 1 → 2 = 2 + 4 = 6 >= 3, median is node 2.
			2
		
	

Example 3:

Input: n = 5, edges = [[0,1,2],[0,2,5],[1,3,1],[2,4,3]], queries = [[3,4],[1,2]]

Output: [2,2]

Explanation:

	
		
			Query
			Path
			Edge

			Weights
			Total

			Path

			Weight
			Half
			Explanation
			Answer
		
	
	
		
			[3, 4]
			3 → 1 → 0 → 2 → 4
			[1, 2, 5, 3]
			11
			5.5
			Sum from 3 → 1 = 1 < 5.5.

			Sum from 3 → 0 = 1 + 2 = 3 < 5.5.

			Sum from 3 → 2 = 1 + 2 + 5 = 8 >= 5.5, median is node 2.
			2
		
		
			[1, 2]
			1 → 0 → 2
			[2, 5]
			7
			3.5
			
			
Sum from 1 → 0 = 2 < 3.5.

			Sum from 1 → 2 = 2 + 5 = 7 >= 3.5, median is node 2.
			
			2
		
	

 

Constraints:

	
• 2 <= n <= 10^5
	
• edges.length == n - 1
	
• edges[i] == [u_i, v_i, w_i]
	
• 0 <= u_i, v_i < n
	
• 1 <= w_i <= 10^9
	
• 1 <= queries.length <= 10^5
	
• queries[j] == [u_j, v_j]
	
• 0 <= u_j, v_j < n
	
• The input is generated such that edges represents a valid tree.

---

## Hints

- Hint 1: Use binary lifting and lowest common ancestor.
- Hint 2: Let the query nodes be u and v, with lowest common ancestor l and total path weight tot.
- Hint 3: If the median lies on the path from u up to l: find the first node where 2 * sum >= tot (equivalently, the last where 2 * sum < tot and move one node above).
- Hint 4: Otherwise, it lies on the path from v up to l: use the same 2 * sum >= tot criterion as you climb.
- Hint 5: In both cases, binary lifting with sparse tables lets you jump by powers of two while tracking cumulative weights to locate the weighted median in O(log n)
