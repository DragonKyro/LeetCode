# 3084. Count Substrings Starting and Ending with Given Character

**Difficulty:** Medium

**Topics:** Math, String, Counting

**Link:** https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/

---

## Description

You are given a string s and a character c. Return the total number of substrings of s that start and end with c.

 

Example 1:

Input: s = "abada", c = "a"

Output: 6

Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".

Example 2:

Input: s = "zzz", c = "z"

Output: 6

Explanation: There are a total of 6 substrings in s and all start and end with "z".

 

Constraints:

	
• 1 <= s.length <= 10^5
	
• s and c consist only of lowercase English letters.

---

## Hints

- Hint 1: Count the number of characters 'c' in string s, let’s call it m.
- Hint 2: We can select 2 numbers i and j such that i <= j are the start and end indices of substring. Note that i and j can be the same.
- Hint 3: The answer is m * (m + 1) / 2.
