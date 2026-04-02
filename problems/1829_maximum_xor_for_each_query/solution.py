from typing import List


class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        xor_sum = 0
        for x in nums:
            xor_sum ^= x
        mask = (1 << maximumBit) - 1
        result = []
        for i in range(len(nums) - 1, -1, -1):
            result.append(xor_sum ^ mask)
            xor_sum ^= nums[i]
        return result
