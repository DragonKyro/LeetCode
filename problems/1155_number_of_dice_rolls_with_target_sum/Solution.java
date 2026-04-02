class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        int MOD = 1_000_000_007;
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int[] newDp = new int[target + 1];
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k && face <= j; face++) {
                    newDp[j] = (int)((newDp[j] + (long)dp[j - face]) % MOD);
                }
            }
            dp = newDp;
        }
        return dp[target];
    }
}
