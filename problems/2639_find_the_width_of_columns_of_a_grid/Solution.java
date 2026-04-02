class Solution {
    public int[] findColumnWidth(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] ans = new int[n];
        for (int c = 0; c < n; c++)
            for (int r = 0; r < m; r++) ans[c] = Math.max(ans[c], String.valueOf(grid[r][c]).length());
        return ans;
    }
}
