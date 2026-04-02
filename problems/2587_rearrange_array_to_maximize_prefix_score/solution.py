from typing import List


class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        prefix = 0
        count = 0
        for n in nums:
            prefix += n
            if prefix > 0:
                count += 1
            else:
                break
        return count
