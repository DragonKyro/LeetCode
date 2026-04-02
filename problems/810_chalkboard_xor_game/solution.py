from typing import List


class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        xor = 0
        for n in nums:
            xor ^= n
        return xor == 0 or len(nums) % 2 == 0
