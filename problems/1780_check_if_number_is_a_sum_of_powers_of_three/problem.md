# 1780. Check if Number is a Sum of Powers of Three

**Difficulty:** Medium

**Topics:** Math

**Link:** https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

---

## Description

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3^x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 3^1 + 3^2

Example 2:

Input: n = 91
Output: true
Explanation: 91 = 3^0 + 3^2 + 3^4

Example 3:

Input: n = 21
Output: false

 

Constraints:

	
• 1 <= n <= 10^7

---

## Hints

- Hint 1: Let's note that the maximum power of 3 you'll use in your soln is 3^16
- Hint 2: The number can not be represented as a sum of powers of 3 if it's ternary presentation has a 2 in it
