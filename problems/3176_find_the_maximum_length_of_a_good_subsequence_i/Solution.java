import java.util.*;

class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length, res = 1;
        int[][] dp = new int[n][k+1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], 1);
            for (int j = 0; j <= k; j++) {
                for (int p = 0; p < i; p++) {
                    if (nums[p] == nums[i]) dp[i][j] = Math.max(dp[i][j], dp[p][j]+1);
                    else if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[p][j-1]+1);
                }
                res = Math.max(res, dp[i][j]);
            }
        }
        return res;
    }
}
