class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++)
                if (grid[i][j] != grid[0][j]) return false;
            if (j+1 < n && grid[0][j] == grid[0][j+1]) return false;
        }
        return true;
    }
}
