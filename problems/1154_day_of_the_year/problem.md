# 1154. Day of the Year

**Difficulty:** Easy

**Topics:** Math, String

**Link:** https://leetcode.com/problems/day-of-the-year/

---

## Description

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.

Example 2:

Input: date = "2019-02-10"
Output: 41

 

Constraints:

	
• date.length == 10
	
• date[4] == date[7] == '-', and all other date[i]'s are digits
	
• date represents a calendar date between Jan 1^st, 1900 and Dec 31^st, 2019.

---

## Hints

- Hint 1: Have a integer array of how many days there are per month.  February gets one extra day if its a leap year.  Then, we can manually count the ordinal as day + (number of days in months before this one).
