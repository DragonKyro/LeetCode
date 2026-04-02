class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) dp[i] = i;
        for (int center = 0; center < n; center++) {
            expand(s, center, center, dp);
            expand(s, center, center + 1, dp);
        }
        return dp[n - 1];
    }
    private void expand(String s, int left, int right, int[] dp) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            dp[right] = Math.min(dp[right], left > 0 ? dp[left - 1] + 1 : 0);
            left--;
            right++;
        }
    }
}
