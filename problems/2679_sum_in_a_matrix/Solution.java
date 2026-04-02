import java.util.*;

class Solution {
    public int matrixSum(int[][] nums) {
        for (int[] row : nums) Arrays.sort(row);
        int score = 0, m = nums.length, n = nums[0].length;
        for (int c = 0; c < n; c++) {
            int mx = 0;
            for (int r = 0; r < m; r++) mx = Math.max(mx, nums[r][n-1-c]);
            score += mx;
        }
        return score;
    }
}
