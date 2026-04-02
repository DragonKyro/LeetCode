class Solution {
    int result = 0, m, n, empty = 0;
    public int uniquePathsIII(int[][] grid) {
        m = grid.length; n = grid[0].length;
        int sr = 0, sc = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) empty++;
                if (grid[i][j] == 1) { sr = i; sc = j; }
            }
        dfs(grid, sr, sc, 1);
        return result;
    }
    private void dfs(int[][] grid, int r, int c, int count) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) return;
        if (grid[r][c] == 2) { if (count == empty) result++; return; }
        grid[r][c] = -1;
        dfs(grid, r+1, c, count+1); dfs(grid, r-1, c, count+1);
        dfs(grid, r, c+1, count+1); dfs(grid, r, c-1, count+1);
        grid[r][c] = 0;
    }
}
