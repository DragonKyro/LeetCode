class Solution {
    public int projectionArea(int[][] grid) {
        int n = grid.length, xy = 0, xz = 0, yz = 0;
        for (int r = 0; r < n; r++) {
            int rowMax = 0, colMax = 0;
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0) xy++;
                rowMax = Math.max(rowMax, grid[r][c]);
                colMax = Math.max(colMax, grid[c][r]);
            }
            xz += rowMax; yz += colMax;
        }
        return xy + xz + yz;
    }
}
