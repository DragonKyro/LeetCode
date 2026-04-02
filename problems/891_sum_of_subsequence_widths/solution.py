from typing import List


class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        nums.sort()
        n = len(nums)
        result = 0
        pow2 = 1
        for i in range(n):
            result = (result + nums[i] * pow2 - nums[n - 1 - i] * pow2) % MOD
            pow2 = pow2 * 2 % MOD
        return result
