class Solution:
    def maxRotateFunction(self, nums: list[int]) -> int:
        n = len(nums)
        total = sum(nums)
        f = sum(i * nums[i] for i in range(n))
        res = f
        for i in range(1, n):
            f = f + total - n * nums[n - i]
            res = max(res, f)
        return res
