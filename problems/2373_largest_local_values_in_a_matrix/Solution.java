class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] result = new int[n-2][n-2];
        for (int i = 0; i < n-2; i++)
            for (int j = 0; j < n-2; j++) {
                int mx = 0;
                for (int di = 0; di < 3; di++)
                    for (int dj = 0; dj < 3; dj++)
                        mx = Math.max(mx, grid[i+di][j+dj]);
                result[i][j] = mx;
            }
        return result;
    }
}
