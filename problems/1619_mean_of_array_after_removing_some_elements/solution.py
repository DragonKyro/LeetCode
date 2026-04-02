from typing import List


class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        n = len(arr)
        trim = n // 20
        return sum(arr[trim:n - trim]) / (n - 2 * trim)
