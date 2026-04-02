class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        num = int(n)
        candidates = set()
        candidates.add(10 ** (length - 1) - 1)
        candidates.add(10 ** length + 1)
        prefix = int(n[:(length + 1) // 2])
        for p in [prefix - 1, prefix, prefix + 1]:
            s = str(p)
            if length % 2 == 0:
                candidate = s + s[::-1]
            else:
                candidate = s + s[-2::-1]
            candidates.add(int(candidate))
        candidates.discard(num)
        return str(min(candidates, key=lambda x: (abs(x - num), x)))
