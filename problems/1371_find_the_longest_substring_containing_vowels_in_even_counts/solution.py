class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vowels = {'a': 0, 'e': 1, 'i': 2, 'o': 3, 'u': 4}
        state = 0
        first = {0: -1}
        res = 0
        for i, c in enumerate(s):
            if c in vowels:
                state ^= (1 << vowels[c])
            if state in first:
                res = max(res, i - first[state])
            else:
                first[state] = i
        return res
