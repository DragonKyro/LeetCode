class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[] dp = new int[n + 1];
        for (int i = 1; i <= m; i++) {
            int[] newDp = new int[n + 1];
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) newDp[j] = dp[j-1] + 1;
                else newDp[j] = Math.max(dp[j], newDp[j-1]);
            }
            dp = newDp;
        }
        return m + n - 2 * dp[n];
    }
}
