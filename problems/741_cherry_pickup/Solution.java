import java.util.*;

class Solution {
    int[][][] memo;
    int n;

    public int cherryPickup(int[][] grid) {
        n = grid.length;
        memo = new int[n][n][n];
        for (int[][] a : memo) for (int[] b : a) Arrays.fill(b, Integer.MIN_VALUE);
        return Math.max(0, dp(grid, 0, 0, 0));
    }

    private int dp(int[][] grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) return -999999;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -999999;
        if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];
        if (memo[r1][c1][r2] != Integer.MIN_VALUE) return memo[r1][c1][r2];
        int cherries = grid[r1][c1];
        if (r1 != r2) cherries += grid[r2][c2];
        cherries += Math.max(Math.max(dp(grid, r1+1, c1, r2+1), dp(grid, r1+1, c1, r2)),
                             Math.max(dp(grid, r1, c1+1, r2+1), dp(grid, r1, c1+1, r2)));
        memo[r1][c1][r2] = cherries;
        return cherries;
    }
}
