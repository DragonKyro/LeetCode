import java.util.*;

class Solution {
    public int findRotateSteps(String ring, String key) {
        int n = ring.length(), m = key.length();
        int[][] dp = new int[m + 1][n];
        for (int k = m - 1; k >= 0; k--) {
            Arrays.fill(dp[k], Integer.MAX_VALUE);
            for (int r = 0; r < n; r++) {
                for (int i = 0; i < n; i++) {
                    if (ring.charAt(i) == key.charAt(k)) {
                        int dist = Math.min(Math.abs(r - i), n - Math.abs(r - i));
                        dp[k][r] = Math.min(dp[k][r], dist + 1 + dp[k + 1][i]);
                    }
                }
            }
        }
        return dp[0][0];
    }
}
