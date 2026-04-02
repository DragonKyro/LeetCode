from typing import List


class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        n = len(nums)
        diff = [target[i] - nums[i] for i in range(n)]
        ops = abs(diff[0])
        for i in range(1, n):
            if diff[i] > 0 and diff[i - 1] > 0:
                ops += max(0, diff[i] - diff[i - 1])
            elif diff[i] < 0 and diff[i - 1] < 0:
                ops += max(0, -diff[i] + diff[i - 1])
            else:
                ops += abs(diff[i])
        return ops
