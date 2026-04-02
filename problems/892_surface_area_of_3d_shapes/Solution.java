class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length, result = 0;
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            if (grid[r][c] > 0) {
                result += 2 + 4 * grid[r][c];
                if (r > 0) result -= 2 * Math.min(grid[r][c], grid[r-1][c]);
                if (c > 0) result -= 2 * Math.min(grid[r][c], grid[r][c-1]);
            }
        }
        return result;
    }
}
