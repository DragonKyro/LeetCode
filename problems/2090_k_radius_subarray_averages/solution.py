class Solution:
    def getAverages(self, nums: list[int], k: int) -> list[int]:
        n = len(nums)
        result = [-1] * n
        if 2 * k + 1 > n:
            return result
        window_sum = sum(nums[:2 * k + 1])
        result[k] = window_sum // (2 * k + 1)
        for i in range(k + 1, n - k):
            window_sum += nums[i + k] - nums[i - k - 1]
            result[i] = window_sum // (2 * k + 1)
        return result
