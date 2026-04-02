class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        ans = 1
        j = 0
        pairs = 0
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                pairs += 1
            while pairs > 1:
                j += 1
                if s[j] == s[j-1]:
                    pairs -= 1
            ans = max(ans, i - j + 1)
        return ans
