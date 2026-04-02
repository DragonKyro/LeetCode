class Solution {
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int MOD = 1000000007;
        long[][] dp = new long[m][n];
        dp[startRow][startColumn] = 1;
        long result = 0;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int move = 0; move < maxMove; move++) {
            long[][] newDp = new long[m][n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] == 0) continue;
                    for (int[] d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) result = (result + dp[i][j]) % MOD;
                        else newDp[ni][nj] = (newDp[ni][nj] + dp[i][j]) % MOD;
                    }
                }
            dp = newDp;
        }
        return (int)result;
    }
}
