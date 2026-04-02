class Solution {
    public int countPartitions(int[] nums, int k) {
        long MOD = 1_000_000_007, total = 1, sum = 0;
        for (int x : nums) sum += x;
        if (sum < 2L * k) return 0;
        long[] dp = new long[k]; dp[0] = 1;
        for (int num : nums) {
            total = total*2%MOD;
            for (int j = k-1; j >= num; j--) dp[j] = (dp[j]+dp[j-num])%MOD;
        }
        long bad = 0;
        for (long d : dp) bad = (bad+d)%MOD;
        return (int)((total - bad*2%MOD + MOD) % MOD);
    }
}
