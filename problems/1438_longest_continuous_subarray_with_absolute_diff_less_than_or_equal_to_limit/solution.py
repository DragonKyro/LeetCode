from typing import List


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        from collections import deque
        max_d = deque()
        min_d = deque()
        left = 0
        res = 0
        for right in range(len(nums)):
            while max_d and nums[right] > max_d[-1]:
                max_d.pop()
            while min_d and nums[right] < min_d[-1]:
                min_d.pop()
            max_d.append(nums[right])
            min_d.append(nums[right])
            while max_d[0] - min_d[0] > limit:
                if nums[left] == max_d[0]:
                    max_d.popleft()
                if nums[left] == min_d[0]:
                    min_d.popleft()
                left += 1
            res = max(res, right - left + 1)
        return res
