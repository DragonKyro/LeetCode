from typing import List


class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        from math import gcd
        n = len(coins)
        def count(x):
            total = 0
            for mask in range(1, 1 << n):
                bits = []
                for i in range(n):
                    if mask & (1 << i):
                        bits.append(coins[i])
                lcm_val = bits[0]
                for b in bits[1:]:
                    lcm_val = lcm_val * b // gcd(lcm_val, b)
                if len(bits) % 2 == 1:
                    total += x // lcm_val
                else:
                    total -= x // lcm_val
            return total
        lo, hi = 1, min(coins) * k
        while lo < hi:
            mid = (lo + hi) // 2
            if count(mid) >= k:
                hi = mid
            else:
                lo = mid + 1
        return lo
