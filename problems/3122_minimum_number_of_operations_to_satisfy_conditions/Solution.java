import java.util.*;

class Solution {
    public int minimumOperations(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] freq = new int[n][10];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                freq[j][grid[i][j]]++;
        int[][] dp = new int[n][10];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
        for (int d = 0; d < 10; d++) dp[0][d] = m - freq[0][d];
        for (int j = 1; j < n; j++)
            for (int d = 0; d < 10; d++) {
                int cost = m - freq[j][d];
                for (int pd = 0; pd < 10; pd++)
                    if (pd != d) dp[j][d] = Math.min(dp[j][d], dp[j-1][pd] + cost);
            }
        int res = Integer.MAX_VALUE;
        for (int d = 0; d < 10; d++) res = Math.min(res, dp[n-1][d]);
        return res;
    }
}
