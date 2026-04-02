from typing import List


class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        res = float('-inf')
        for i in range(n - 1, n - 1 - k, -1):
            total = 0
            j = i
            while j >= 0:
                total += energy[j]
                res = max(res, total)
                j -= k
        return res
