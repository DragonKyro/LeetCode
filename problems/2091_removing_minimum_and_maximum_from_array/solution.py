class Solution:
    def minimumDeletions(self, nums: list[int]) -> int:
        n = len(nums)
        min_idx = nums.index(min(nums))
        max_idx = nums.index(max(nums))
        left = min(min_idx, max_idx) + 1
        right = n - max(min_idx, max_idx)
        both = left + right
        from_left = max(min_idx, max_idx) + 1
        from_right = n - min(min_idx, max_idx)
        return min(both, from_left, from_right)
