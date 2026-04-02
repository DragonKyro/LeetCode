import java.util.*;

class Solution {
    int[] suffix;
    int[][] memo;
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        suffix = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
        memo = new int[n][n + 1];
        for (int[] row : memo) Arrays.fill(row, -1);
        return dp(0, 1, n);
    }
    private int dp(int i, int m, int n) {
        if (i >= n) return 0;
        if (2 * m >= n - i) return suffix[i];
        if (memo[i][m] != -1) return memo[i][m];
        int best = 0;
        for (int x = 1; x <= 2 * m; x++) {
            best = Math.max(best, suffix[i] - dp(i + x, Math.max(m, x), n));
        }
        return memo[i][m] = best;
    }
}
