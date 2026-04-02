from typing import List


class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        def count(bound):
            ans = cnt = 0
            for num in nums:
                cnt = cnt + 1 if num <= bound else 0
                ans += cnt
            return ans
        return count(right) - count(left - 1)
