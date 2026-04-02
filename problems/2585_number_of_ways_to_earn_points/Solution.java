class Solution {
    public int waysToReachTarget(int target, int[][] types) {
        int MOD = 1_000_000_007;
        long[] dp = new long[target+1]; dp[0] = 1;
        for (int[] t : types) {
            for (int j = target; j >= 0; j--)
                for (int k = 1; k <= t[0]; k++)
                    if (j - k*t[1] >= 0) dp[j] = (dp[j] + dp[j-k*t[1]]) % MOD;
        }
        return (int) dp[target];
    }
}
