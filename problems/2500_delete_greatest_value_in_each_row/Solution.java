import java.util.*;

class Solution {
    public int deleteGreatestValue(int[][] grid) {
        for (int[] row : grid) Arrays.sort(row);
        int result = 0;
        for (int j = 0; j < grid[0].length; j++) {
            int mx = 0;
            for (int[] row : grid) mx = Math.max(mx, row[j]);
            result += mx;
        }
        return result;
    }
}
