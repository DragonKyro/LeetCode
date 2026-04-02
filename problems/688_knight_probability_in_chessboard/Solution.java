class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        double[][] dp = new double[n][n];
        dp[row][column] = 1.0;
        int[][] moves = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
        for (int step = 0; step < k; step++) {
            double[][] newDp = new double[n][n];
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] > 0) {
                        for (int[] m : moves) {
                            int nr = r + m[0], nc = c + m[1];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                                newDp[nr][nc] += dp[r][c] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = newDp;
        }
        double sum = 0;
        for (double[] row2 : dp) for (double v : row2) sum += v;
        return sum;
    }
}
