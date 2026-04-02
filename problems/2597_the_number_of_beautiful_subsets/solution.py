from typing import List


class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        count = 0
        def backtrack(idx: int, used: dict):
            nonlocal count
            if idx == len(nums):
                if used:
                    count += 1
                return
            backtrack(idx + 1, used)
            if used.get(nums[idx] - k, 0) == 0 and used.get(nums[idx] + k, 0) == 0:
                used[nums[idx]] = used.get(nums[idx], 0) + 1
                backtrack(idx + 1, used)
                used[nums[idx]] -= 1
                if used[nums[idx]] == 0:
                    del used[nums[idx]]
        backtrack(0, {})
        return count
