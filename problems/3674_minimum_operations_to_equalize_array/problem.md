# 3674. Minimum Operations to Equalize Array

**Difficulty:** Easy

**Topics:** Array, Bit Manipulation, Brainteaser

**Link:** https://leetcode.com/problems/minimum-operations-to-equalize-array/

---

## Description

You are given an integer array nums of length n.

In one operation, choose any subarray nums[l...r] (0 <= l <= r < n) and replace each element in that subarray with the bitwise AND of all elements.

Return the minimum number of operations required to make all elements of nums equal.
A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2]

Output: 1

Explanation:

Choose nums[0...1]: (1 AND 2) = 0, so the array becomes [0, 0] and all elements are equal in 1 operation.

Example 2:

Input: nums = [5,5,5]

Output: 0

Explanation:

nums is [5, 5, 5] which already has all elements equal, so 0 operations are required.

 

Constraints:

	
• 1 <= n == nums.length <= 100
	
• 1 <= nums[i] <= 10^5

---

## Hints

- Hint 1: If all elements of nums are already equal, how many operations are needed?
- Hint 2: The answer is either 0 or 1.
- Hint 3: The answer is 0 if all values in the array are initially equal, and 1 otherwise, since you can apply the AND operation on the whole array in one step.
