class Solution:
    def minAnagramLength(self, s: str) -> int:
        from collections import Counter
        n = len(s)
        for k in range(1, n + 1):
            if n % k != 0:
                continue
            base = Counter(s[:k])
            ok = True
            for i in range(k, n, k):
                if Counter(s[i:i+k]) != base:
                    ok = False
                    break
            if ok:
                return k
        return n
