class Solution:
    def maxScoreSightseeingPair(self, values: list[int]) -> int:
        ans = 0
        best = values[0] + 0
        for j in range(1, len(values)):
            ans = max(ans, best + values[j] - j)
            best = max(best, values[j] + j)
        return ans
