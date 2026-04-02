class Solution:
    def numSplits(self, s: str) -> int:
        from collections import Counter
        left = Counter()
        right = Counter(s)
        res = 0
        for c in s:
            left[c] += 1
            right[c] -= 1
            if right[c] == 0:
                del right[c]
            if len(left) == len(right):
                res += 1
        return res
