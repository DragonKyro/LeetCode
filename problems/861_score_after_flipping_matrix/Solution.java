class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) if (grid[i][0] == 0)
            for (int j = 0; j < n; j++) grid[i][j] ^= 1;
        for (int j = 1; j < n; j++) {
            int ones = 0;
            for (int i = 0; i < m; i++) ones += grid[i][j];
            if (ones < m - ones)
                for (int i = 0; i < m; i++) grid[i][j] ^= 1;
        }
        int result = 0;
        for (int[] row : grid) {
            int val = 0;
            for (int b : row) val = val * 2 + b;
            result += val;
        }
        return result;
    }
}
