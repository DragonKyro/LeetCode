from typing import List


class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        max_len = 0
        for i in range(len(nums)):
            if nums[i] == -1:
                continue
            count = 0
            j = i
            while nums[j] != -1:
                temp = nums[j]
                nums[j] = -1
                j = temp
                count += 1
            max_len = max(max_len, count)
        return max_len
