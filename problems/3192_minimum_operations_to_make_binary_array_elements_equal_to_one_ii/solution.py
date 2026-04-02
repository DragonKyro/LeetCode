from typing import List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ops = 0
        flip = 0
        for x in nums:
            x ^= (flip & 1)
            if x == 0:
                ops += 1
                flip += 1
        return ops
