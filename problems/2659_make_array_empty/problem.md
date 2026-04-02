# 2659. Make Array Empty

**Difficulty:** Hard

**Topics:** Array, Binary Search, Greedy, Binary Indexed Tree, Segment Tree, Sorting, Ordered Set

**Link:** https://leetcode.com/problems/make-array-empty/

---

## Description

You are given an integer array nums containing distinct numbers, and you can perform the following operations until the array is empty:

	
• If the first element has the smallest value, remove it
	
• Otherwise, put the first element at the end of the array.

Return an integer denoting the number of operations it takes to make nums empty.

 

Example 1:

Input: nums = [3,4,-1]
Output: 5

	
		
			Operation
			Array
		
	
	
		
			1
			[4, -1, 3]
		
		
			2
			[-1, 3, 4]
		
		
			3
			[3, 4]
		
		
			4
			[4]
		
		
			5
			[]
		
	

Example 2:

Input: nums = [1,2,4,3]
Output: 5

	
		
			Operation
			Array
		
	
	
		
			1
			[2, 4, 3]
		
		
			2
			[4, 3]
		
		
			3
			[3, 4]
		
		
			4
			[4]
		
		
			5
			[]
		
	

Example 3:

Input: nums = [1,2,3]
Output: 3

	
		
			Operation
			Array
		
	
	
		
			1
			[2, 3]
		
		
			2
			[3]
		
		
			3
			[]
		
	

 

Constraints:

	
• 1 <= nums.length <= 10^5
	
• -10^9 <= nums[i] <= 10^9
	
• All values in nums are distinct.

---

## Hints

- Hint 1: Understand the order in which the indices are removed from the array.
- Hint 2: We don’t really need to delete or move the elements, only the array length matters.
- Hint 3: Upon removing an index, decide how many steps it takes to move to the next one.
- Hint 4: Use a data structure to speed up the calculation.
