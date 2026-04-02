from typing import List


class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        from collections import defaultdict
        import sortedcontainers
        ans = 0
        j = 0
        sl = sortedcontainers.SortedList()
        for i in range(len(nums)):
            sl.add(nums[i])
            while sl[-1] - sl[0] > 2:
                sl.remove(nums[j])
                j += 1
            ans += i - j + 1
        return ans
