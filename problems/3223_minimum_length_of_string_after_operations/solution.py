class Solution:
    def minimumLength(self, s: str) -> int:
        from collections import Counter
        cnt = Counter(s)
        res = 0
        for v in cnt.values():
            res += 2 if v % 2 == 0 else 1
        return res
