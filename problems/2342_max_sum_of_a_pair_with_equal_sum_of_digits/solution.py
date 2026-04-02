from typing import List


class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        def digitSum(n: int) -> int:
            s = 0
            while n:
                s += n % 10
                n //= 10
            return s
        best = {}
        result = -1
        for num in nums:
            ds = digitSum(num)
            if ds in best:
                result = max(result, best[ds] + num)
                best[ds] = max(best[ds], num)
            else:
                best[ds] = num
        return result
