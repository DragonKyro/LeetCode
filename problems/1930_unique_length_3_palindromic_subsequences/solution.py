class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        result = 0
        for c in set(s):
            first = s.index(c)
            last = s.rindex(c)
            if last - first > 1:
                result += len(set(s[first + 1:last]))
        return result
