class Solution {
    public int maxSumDivThree(int[] nums) {
        int[] dp = {0, Integer.MIN_VALUE, Integer.MIN_VALUE};
        for (int x : nums) {
            int[] temp = dp.clone();
            for (int i = 0; i < 3; i++)
                dp[(i + x) % 3] = Math.max(dp[(i + x) % 3], temp[i] + x);
        }
        return dp[0];
    }
}
