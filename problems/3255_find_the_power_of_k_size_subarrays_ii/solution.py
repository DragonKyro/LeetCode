from typing import List


class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        cnt = 1
        res = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i-1] + 1:
                cnt += 1
            else:
                cnt = 1
            if i >= k - 1:
                res.append(nums[i] if cnt >= k else -1)
        return res
