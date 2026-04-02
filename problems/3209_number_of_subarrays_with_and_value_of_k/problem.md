# 3209. Number of Subarrays With AND Value of K

**Difficulty:** Hard

**Topics:** Array, Binary Search, Bit Manipulation, Segment Tree

**Link:** https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/

---

## Description

Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.

 

Example 1:

Input: nums = [1,1,1], k = 1

Output: 6

Explanation:

All subarrays contain only 1's.

Example 2:

Input: nums = [1,1,2], k = 1

Output: 3

Explanation:

Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].

Example 3:

Input: nums = [1,2,3], k = 2

Output: 2

Explanation:

Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].

 

Constraints:

	
• 1 <= nums.length <= 10^5
	
• 0 <= nums[i], k <= 10^9

---

## Hints

- Hint 1: Let’s say we want to count the number of pairs (l, r) such that nums[l] & nums[l + 1] & … & nums[r] == k.
- Hint 2: Fix the left index l.
- Hint 3: Note that if you increase r for a fixed l, then the AND value of the subarray either decreases or remains unchanged.
- Hint 4: Therefore, consider using binary search.
- Hint 5: To calculate the AND value of a subarray, use sparse tables.
