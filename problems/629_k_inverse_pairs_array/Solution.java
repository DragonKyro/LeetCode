class Solution {
    public int kInversePairs(int n, int k) {
        int MOD = 1000000007;
        int[] dp = new int[k + 1];
        dp[0] = 1;
        for (int i = 2; i <= n; i++) {
            int[] newDp = new int[k + 1];
            long[] prefix = new long[k + 2];
            for (int j = 0; j <= k; j++) prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            for (int j = 0; j <= k; j++) {
                newDp[j] = (int)((prefix[j + 1] - prefix[Math.max(0, j - i + 1)] + MOD) % MOD);
            }
            dp = newDp;
        }
        return dp[k];
    }
}
