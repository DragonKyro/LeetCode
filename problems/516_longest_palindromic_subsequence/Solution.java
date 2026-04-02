class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int[] newDp = new int[n];
            newDp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) newDp[j] = dp[j - 1] + 2;
                else newDp[j] = Math.max(dp[j], newDp[j - 1]);
            }
            dp = newDp;
        }
        return dp[n - 1];
    }
}
