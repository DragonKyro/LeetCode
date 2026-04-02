import java.util.*;

class Solution {
    public int paintWalls(int[] cost, int[] time) {
        int n = cost.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = n; j >= 1; j--)
                dp[j] = Math.min(dp[j], dp[Math.max(j-time[i]-1, 0)] + cost[i]);
        return dp[n];
    }
}
