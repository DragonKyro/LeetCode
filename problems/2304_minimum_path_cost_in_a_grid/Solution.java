import java.util.*;

class Solution {
    public int minPathCost(int[][] grid, int[][] moveCost) {
        int m = grid.length, n = grid[0].length;
        int[] dp = grid[0].clone();
        for (int i = 1; i < m; i++) {
            int[] newDp = new int[n];
            Arrays.fill(newDp, Integer.MAX_VALUE);
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    newDp[j] = Math.min(newDp[j], dp[k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
            dp = newDp;
        }
        int res = Integer.MAX_VALUE;
        for (int v : dp) res = Math.min(res, v);
        return res;
    }
}
