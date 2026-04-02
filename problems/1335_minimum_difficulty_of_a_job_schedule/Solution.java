import java.util.*;

class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        if (n < d) return -1;
        int[][] dp = new int[d][n];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
        dp[0][0] = jobDifficulty[0];
        for (int j = 1; j < n; j++) dp[0][j] = Math.max(dp[0][j-1], jobDifficulty[j]);
        for (int i = 1; i < d; i++)
            for (int j = i; j < n; j++) {
                int maxD = 0;
                for (int k = j; k >= i; k--) {
                    maxD = Math.max(maxD, jobDifficulty[k]);
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][k-1] + maxD);
                }
            }
        return dp[d-1][n-1];
    }
}
