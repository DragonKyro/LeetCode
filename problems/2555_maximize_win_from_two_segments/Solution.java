class Solution {
    public int maximizeWin(int[] pos, int k) {
        int n = pos.length, ans = 0, j = 0;
        int[] dp = new int[n+1];
        for (int i = 0; i < n; i++) {
            while (pos[i]-pos[j] > k) j++;
            dp[i+1] = Math.max(dp[i], i-j+1);
            ans = Math.max(ans, i-j+1+dp[j]);
        }
        return ans;
    }
}
