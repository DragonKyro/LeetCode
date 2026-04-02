class Solution:
    def minSteps(self, s: str, t: str) -> int:
        from collections import Counter
        cs = Counter(s)
        ct = Counter(t)
        return sum((cs[c] - ct[c]) for c in cs if cs[c] > ct[c])
