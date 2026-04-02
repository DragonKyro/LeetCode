class Solution:
    def maxSumDivThree(self, nums: list[int]) -> int:
        dp = [0, float('-inf'), float('-inf')]
        for x in nums:
            temp = dp[:]
            for i in range(3):
                dp[(i + x) % 3] = max(dp[(i + x) % 3], temp[i] + x)
        return dp[0]
