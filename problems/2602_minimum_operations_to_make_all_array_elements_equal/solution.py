from typing import List


class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        from bisect import bisect_left
        nums.sort()
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        ans = []
        for q in queries:
            idx = bisect_left(nums, q)
            left = q * idx - prefix[idx]
            right = (prefix[n] - prefix[idx]) - q * (n - idx)
            ans.append(left + right)
        return ans
