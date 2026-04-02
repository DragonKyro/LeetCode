class Solution {
    public int minFlips(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int rowCost = 0, colCost = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n/2; j++)
                if (grid[i][j] != grid[i][n-1-j]) rowCost++;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m/2; i++)
                if (grid[i][j] != grid[m-1-i][j]) colCost++;
        return Math.min(rowCost, colCost);
    }
}
