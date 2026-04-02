class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        import math
        limit = int(math.isqrt(r))
        sieve = [True] * (limit + 1)
        sieve[0] = sieve[1] = False
        for i in range(2, int(math.isqrt(limit)) + 1):
            if sieve[i]:
                for j in range(i*i, limit + 1, i):
                    sieve[j] = False
        special = 0
        for p in range(2, limit + 1):
            if sieve[p] and l <= p * p <= r:
                special += 1
        return (r - l + 1) - special
