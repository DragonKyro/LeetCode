import java.util.*;

class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int[][] grid = new int[n][n];
        for (int[] row : grid) Arrays.fill(row, 1);
        for (int[] m : mines) grid[m[0]][m[1]] = 0;
        int[][] left = new int[n][n], right = new int[n][n], up = new int[n][n], down = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) left[i][j] = grid[i][j] == 0 ? 0 : (j > 0 ? left[i][j-1] + 1 : 1);
            for (int j = n-1; j >= 0; j--) right[i][j] = grid[i][j] == 0 ? 0 : (j < n-1 ? right[i][j+1] + 1 : 1);
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) up[i][j] = grid[i][j] == 0 ? 0 : (i > 0 ? up[i-1][j] + 1 : 1);
            for (int i = n-1; i >= 0; i--) down[i][j] = grid[i][j] == 0 ? 0 : (i < n-1 ? down[i+1][j] + 1 : 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = Math.max(ans, Math.min(Math.min(left[i][j], right[i][j]), Math.min(up[i][j], down[i][j])));
        return ans;
    }
}
