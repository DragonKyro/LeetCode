import java.util.*;

class Solution {
    public int knightDialer(int n) {
        int MOD = 1_000_000_007;
        int[][] moves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        long[] dp = new long[10];
        Arrays.fill(dp, 1);
        for (int k = 1; k < n; k++) {
            long[] newDp = new long[10];
            for (int i = 0; i < 10; i++)
                for (int j : moves[i])
                    newDp[j] = (newDp[j] + dp[i]) % MOD;
            dp = newDp;
        }
        long result = 0;
        for (long v : dp) result = (result + v) % MOD;
        return (int) result;
    }
}
