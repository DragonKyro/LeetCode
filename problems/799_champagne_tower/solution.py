class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [[0.0] * (i + 1) for i in range(query_row + 1)]
        dp[0][0] = float(poured)
        for i in range(query_row):
            for j in range(len(dp[i])):
                overflow = (dp[i][j] - 1.0) / 2.0
                if overflow > 0:
                    dp[i+1][j] += overflow
                    dp[i+1][j+1] += overflow
        return min(1.0, dp[query_row][query_glass])
