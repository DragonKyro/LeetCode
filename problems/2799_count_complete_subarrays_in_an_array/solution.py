from typing import List


class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        total = len(set(nums))
        n = len(nums)
        ans = 0
        for i in range(n):
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                if len(s) == total:
                    ans += n - j
                    break
        return ans
