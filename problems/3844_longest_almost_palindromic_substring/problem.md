# 3844. Longest Almost-Palindromic Substring

**Difficulty:** Medium

**Topics:** Two Pointers, String, Dynamic Programming

**Link:** https://leetcode.com/problems/longest-almost-palindromic-substring/

---

## Description

You are given a string s consisting of lowercase English letters.

A substring is almost-palindromic if it becomes a palindrome after removing exactly one character from it.

Return an integer denoting the length of the longest almost-palindromic substring in s.

 

Example 1:

Input: s = "abca"

Output: 4

Explanation:

Choose the substring "abca".

	
• Remove "abca".
	
• The string becomes "aba", which is a palindrome.
	
• Therefore, "abca" is almost-palindromic.

Example 2:

Input: s = "abba"

Output: 4

Explanation:

Choose the substring "abba".

	
• Remove "abba".
	
• The string becomes "aba", which is a palindrome.
	
• Therefore, "abba" is almost-palindromic.

Example 3:

Input: s = "zzabba"

Output: 5

Explanation:

Choose the substring "zzabba".

	
• Remove "zabba".
	
• The string becomes "abba", which is a palindrome.
	
• Therefore, "zabba" is almost-palindromic.

 

Constraints:

	
• 2 <= s.length <= 2500
	
• s consists of only lowercase English letters.

---

## Hints

- Hint 1: Solve greedily
- Hint 2: Fix the center (consider both odd and even centers) and expand outwards
- Hint 3: On the first mismatch, try skipping the left character and continue expanding, and also try skipping the right character; take the longer result
- Hint 4: Track the maximum length found across all centers
