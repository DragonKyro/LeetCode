class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int r1 = m, r2 = 0, c1 = n, c2 = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    r1 = Math.min(r1,i); r2 = Math.max(r2,i);
                    c1 = Math.min(c1,j); c2 = Math.max(c2,j);
                }
        return (r2-r1+1)*(c2-c1+1);
    }
}
