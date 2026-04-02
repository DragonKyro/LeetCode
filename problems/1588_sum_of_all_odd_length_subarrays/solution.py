from typing import List


class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        total = 0
        n = len(arr)
        for i in range(n):
            total += ((i + 1) * (n - i) + 1) // 2 * arr[i]
        return total
