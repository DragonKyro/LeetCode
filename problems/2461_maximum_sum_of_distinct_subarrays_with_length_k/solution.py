from typing import List


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        window_sum = sum(nums[:k])
        count = Counter(nums[:k])
        result = window_sum if len(count) == k else 0
        for i in range(k, len(nums)):
            window_sum += nums[i] - nums[i - k]
            count[nums[i]] += 1
            count[nums[i - k]] -= 1
            if count[nums[i - k]] == 0:
                del count[nums[i - k]]
            if len(count) == k:
                result = max(result, window_sum)
        return result
