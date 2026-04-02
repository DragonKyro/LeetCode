import java.util.*;

class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Set<Integer> minRows = new HashSet<>();
        for (int[] row : matrix) {
            int min = row[0]; for (int x : row) min = Math.min(min, x); minRows.add(min);
        }
        List<Integer> res = new ArrayList<>();
        for (int j = 0; j < n; j++) {
            int max = matrix[0][j]; for (int i = 1; i < m; i++) max = Math.max(max, matrix[i][j]);
            if (minRows.contains(max)) res.add(max);
        }
        return res;
    }
}
