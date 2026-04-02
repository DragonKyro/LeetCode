class Solution:
    def maxAbsValExpr(self, arr1: list[int], arr2: list[int]) -> int:
        n = len(arr1)
        result = 0
        for p, q in [(1, 1), (1, -1), (-1, 1), (-1, -1)]:
            min_val = float('inf')
            max_val = float('-inf')
            for i in range(n):
                val = p * arr1[i] + q * arr2[i] + i
                min_val = min(min_val, val)
                max_val = max(max_val, val)
            result = max(result, max_val - min_val)
        return result
