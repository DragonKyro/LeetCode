class Solution {
    public int maximumLength(int[] nums, int k) {
        int res = 0;
        for (int c = 0; c < k; c++) {
            int[] dp = new int[k];
            for (int x : nums) {
                int r = x % k;
                int need = (c - r % k + k) % k;
                dp[r] = dp[need] + 1;
                res = Math.max(res, dp[r]);
            }
        }
        return res;
    }
}
