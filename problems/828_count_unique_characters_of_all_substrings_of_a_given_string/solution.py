class Solution:
    def uniqueLetterString(self, s: str) -> int:
        index = {}
        result = 0
        for i, c in enumerate(s):
            if c not in index:
                index[c] = [-1, -1]
            prev2, prev1 = index[c]
            result += (i - prev1) * (prev1 - prev2)
            index[c] = [prev1, i]
        for c in index:
            prev2, prev1 = index[c]
            result += (len(s) - prev1) * (prev1 - prev2)
        return result
