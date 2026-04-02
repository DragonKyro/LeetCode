class Solution {
    int[][] grid;
    int m, n;
    public int findMaxFish(int[][] grid) {
        this.grid = grid; m = grid.length; n = grid[0].length;
        int ans = 0;
        for (int r = 0; r < m; r++) for (int c = 0; c < n; c++) ans = Math.max(ans, dfs(r, c));
        return ans;
    }
    int dfs(int r, int c) {
        if (r<0||r>=m||c<0||c>=n||grid[r][c]==0) return 0;
        int f = grid[r][c]; grid[r][c] = 0;
        return f + dfs(r+1,c)+dfs(r-1,c)+dfs(r,c+1)+dfs(r,c-1);
    }
}
