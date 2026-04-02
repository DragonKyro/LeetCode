class Solution:
    def maxSumOfThreeSubarrays(self, nums: list[int], k: int) -> list[int]:
        n = len(nums)
        sums = [0] * (n - k + 1)
        s = sum(nums[:k])
        sums[0] = s
        for i in range(1, n - k + 1):
            s += nums[i + k - 1] - nums[i - 1]
            sums[i] = s
        left = [0] * len(sums)
        best = 0
        for i in range(len(sums)):
            if sums[i] > sums[best]:
                best = i
            left[i] = best
        right = [0] * len(sums)
        best = len(sums) - 1
        for i in range(len(sums) - 1, -1, -1):
            if sums[i] >= sums[best]:
                best = i
            right[i] = best
        result = [0, 0, 0]
        max_sum = 0
        for j in range(k, len(sums) - k):
            i, l = left[j - k], right[j + k]
            total = sums[i] + sums[j] + sums[l]
            if total > max_sum:
                max_sum = total
                result = [i, j, l]
        return result
