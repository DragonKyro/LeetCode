class Solution {
    int[][] grid;
    int m, n;
    public int getMaximumGold(int[][] grid) {
        this.grid = grid; m = grid.length; n = grid[0].length;
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 0) ans = Math.max(ans, dfs(i, j));
        return ans;
    }
    int dfs(int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
        int val = grid[r][c]; grid[r][c] = 0;
        int best = 0;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int[] d : dirs) best = Math.max(best, dfs(r+d[0], c+d[1]));
        grid[r][c] = val;
        return val + best;
    }
}
