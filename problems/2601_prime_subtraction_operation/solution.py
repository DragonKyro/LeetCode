from typing import List


class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        def sieve(n):
            is_p = [True] * (n + 1)
            is_p[0] = is_p[1] = False
            for i in range(2, int(n**0.5) + 1):
                if is_p[i]:
                    for j in range(i*i, n+1, i): is_p[j] = False
            return [i for i in range(2, n+1) if is_p[i]]
        primes = sieve(1000)
        prev = 0
        for n in nums:
            best = n
            for p in primes:
                if p >= n: break
                if n - p > prev:
                    best = n - p
                    break
            if best <= prev: return False
            prev = best
        return True
