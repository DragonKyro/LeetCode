class Solution {
    public int[] findBall(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] result = new int[n];
        for (int col = 0; col < n; col++) {
            int c = col;
            boolean stuck = false;
            for (int row = 0; row < m; row++) {
                int nc = c + grid[row][c];
                if (nc < 0 || nc >= n || grid[row][nc] != grid[row][c]) {
                    stuck = true;
                    break;
                }
                c = nc;
            }
            result[col] = stuck ? -1 : c;
        }
        return result;
    }
}
