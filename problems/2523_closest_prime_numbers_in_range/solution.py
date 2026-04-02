from typing import List


class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        sieve = [True] * (right + 1)
        if right >= 0: sieve[0] = False
        if right >= 1: sieve[1] = False
        for i in range(2, int(right**0.5) + 1):
            if sieve[i]:
                for j in range(i*i, right + 1, i):
                    sieve[j] = False
        primes = [i for i in range(left, right + 1) if sieve[i]]
        if len(primes) < 2: return [-1, -1]
        best = [primes[0], primes[1]]
        for i in range(1, len(primes) - 1):
            if primes[i+1] - primes[i] < best[1] - best[0]:
                best = [primes[i], primes[i+1]]
        return best
