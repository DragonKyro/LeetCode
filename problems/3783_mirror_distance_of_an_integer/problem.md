# 3783. Mirror Distance of an Integer

**Difficulty:** Easy

**Topics:** Math

**Link:** https://leetcode.com/problems/mirror-distance-of-an-integer/

---

## Description

You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.

 

Example 1:

Input: n = 25

Output: 27

Explanation:

	
• reverse(25) = 52.
	
• Thus, the answer is abs(25 - 52) = 27.

Example 2:

Input: n = 10

Output: 9

Explanation:

	
• reverse(10) = 01 which is 1.
	
• Thus, the answer is abs(10 - 1) = 9.

Example 3:

Input: n = 7

Output: 0

Explanation:

	
• reverse(7) = 7.
	
• Thus, the answer is abs(7 - 7) = 0.

 

Constraints:

	
• 1 <= n <= 10^9

---

## Hints

- Hint 1: Simulate as described
