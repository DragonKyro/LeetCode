class Solution {
    public int numDecodings(String s) {
        long MOD = 1000000007;
        int n = s.length();
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = s.charAt(0) == '*' ? 9 : (s.charAt(0) == '0' ? 0 : 1);
        for (int i = 2; i <= n; i++) {
            char c = s.charAt(i - 1), p = s.charAt(i - 2);
            if (c == '*') dp[i] = 9 * dp[i - 1] % MOD;
            else if (c != '0') dp[i] = dp[i - 1];
            if (p == '*') {
                if (c == '*') dp[i] = (dp[i] + 15 * dp[i - 2]) % MOD;
                else if (c <= '6') dp[i] = (dp[i] + 2 * dp[i - 2]) % MOD;
                else dp[i] = (dp[i] + dp[i - 2]) % MOD;
            } else if (p == '1') {
                if (c == '*') dp[i] = (dp[i] + 9 * dp[i - 2]) % MOD;
                else dp[i] = (dp[i] + dp[i - 2]) % MOD;
            } else if (p == '2') {
                if (c == '*') dp[i] = (dp[i] + 6 * dp[i - 2]) % MOD;
                else if (c <= '6') dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }
        return (int)(dp[n] % MOD);
    }
}
