import java.util.*;

class Solution {
    public int maxScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int res = Integer.MIN_VALUE;
        int[][] mn = new int[m][n];
        for (int[] row : mn) Arrays.fill(row, Integer.MAX_VALUE);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0) mn[i][j] = Math.min(mn[i][j], mn[i-1][j]);
                if (j > 0) mn[i][j] = Math.min(mn[i][j], mn[i][j-1]);
                res = Math.max(res, grid[i][j] - mn[i][j]);
                mn[i][j] = Math.min(mn[i][j], grid[i][j]);
            }
        return res;
    }
}
