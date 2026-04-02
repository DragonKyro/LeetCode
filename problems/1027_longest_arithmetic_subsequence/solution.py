class Solution:
    def longestArithSeqLength(self, nums: list[int]) -> int:
        dp = [{} for _ in range(len(nums))]
        ans = 2
        for i in range(len(nums)):
            for j in range(i):
                diff = nums[i] - nums[j]
                dp[i][diff] = dp[j].get(diff, 1) + 1
                ans = max(ans, dp[i][diff])
        return ans
