class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 1];
        for (int t = 1; t <= target; t++) {
            int k = Integer.SIZE - Integer.numberOfLeadingZeros(t);
            if ((1 << k) - 1 == t) { dp[t] = k; continue; }
            dp[t] = k + 1 + dp[(1 << k) - 1 - t];
            for (int j = 0; j < k - 1; j++)
                dp[t] = Math.min(dp[t], k + j + 1 + dp[t - (1 << (k - 1)) + (1 << j)]);
        }
        return dp[target];
    }
}
