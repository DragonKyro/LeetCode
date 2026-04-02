class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        int MOD = 1_000_000_007;
        int[][] dp = new int[n + 1][minProfit + 1];
        dp[0][0] = 1;
        for (int k = 0; k < group.length; k++) {
            int g = group[k], p = profit[k];
            for (int i = n; i >= g; i--)
                for (int j = minProfit; j >= 0; j--)
                    dp[i][Math.min(j + p, minProfit)] = (dp[i][Math.min(j + p, minProfit)] + dp[i - g][j]) % MOD;
        }
        int res = 0;
        for (int i = 0; i <= n; i++) res = (res + dp[i][minProfit]) % MOD;
        return res;
    }
}
