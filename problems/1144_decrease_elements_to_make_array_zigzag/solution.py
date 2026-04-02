class Solution:
    def movesToMakeZigzag(self, nums: list[int]) -> int:
        result = [0, 0]
        for i in range(len(nums)):
            left = nums[i - 1] if i > 0 else float('inf')
            right = nums[i + 1] if i < len(nums) - 1 else float('inf')
            diff = nums[i] - min(left, right) + 1
            if diff > 0:
                result[i % 2] += diff
        return min(result)
