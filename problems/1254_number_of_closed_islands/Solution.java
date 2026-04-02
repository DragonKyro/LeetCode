class Solution {
    int[][] grid;
    int m, n;
    public int closedIsland(int[][] grid) {
        this.grid = grid; m = grid.length; n = grid[0].length;
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0 && dfs(i, j)) count++;
        return count;
    }
    boolean dfs(int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        if (grid[r][c] == 1) return true;
        grid[r][c] = 1;
        boolean a = dfs(r+1,c), b = dfs(r-1,c), cc = dfs(r,c+1), d = dfs(r,c-1);
        return a && b && cc && d;
    }
}
