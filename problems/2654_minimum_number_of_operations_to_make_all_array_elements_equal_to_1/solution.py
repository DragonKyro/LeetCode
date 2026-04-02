from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        from math import gcd
        from functools import reduce
        g = reduce(gcd, nums)
        if g > 1:
            return -1
        n = len(nums)
        ans = n - 1
        for i in range(n):
            g = nums[i]
            for j in range(i + 1, n):
                g = gcd(g, nums[j])
                if g == 1:
                    ans = min(ans, j - i + n - 2)
                    break
        return ans
