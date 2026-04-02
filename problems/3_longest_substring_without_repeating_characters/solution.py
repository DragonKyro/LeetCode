class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        left = 0
        res = 0
        for right, c in enumerate(s):
            if c in seen and seen[c] >= left:
                left = seen[c] + 1
            seen[c] = right
            res = max(res, right - left + 1)
        return res
