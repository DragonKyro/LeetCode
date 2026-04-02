class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int n = grid.length, result = 0;
        int[] rowMax = new int[n], colMax = new int[n];
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            rowMax[r] = Math.max(rowMax[r], grid[r][c]);
            colMax[c] = Math.max(colMax[c], grid[r][c]);
        }
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++)
            result += Math.min(rowMax[r], colMax[c]) - grid[r][c];
        return result;
    }
}
