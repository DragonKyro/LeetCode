from typing import List


class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        result = 1
        start = nums[0]
        for num in nums:
            if num - start > k:
                result += 1
                start = num
        return result
