class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length + 2;
        int[] arr = new int[n];
        arr[0] = arr[n - 1] = 1;
        for (int i = 0; i < nums.length; i++) arr[i + 1] = nums[i];
        int[][] dp = new int[n][n];
        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int k = left + 1; k < right; k++) {
                    dp[left][right] = Math.max(dp[left][right],
                        dp[left][k] + dp[k][right] + arr[left] * arr[k] * arr[right]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
