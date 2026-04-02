class Solution {
    public int maxMoves(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m][n];
        int ans = 0;
        for (int c = n-2; c >= 0; c--)
            for (int r = 0; r < m; r++)
                for (int dr = -1; dr <= 1; dr++) {
                    int nr = r + dr;
                    if (nr>=0&&nr<m&&grid[nr][c+1]>grid[r][c])
                        dp[r][c] = Math.max(dp[r][c], 1+dp[nr][c+1]);
                }
        for (int r = 0; r < m; r++) ans = Math.max(ans, dp[r][0]);
        return ans;
    }
}
