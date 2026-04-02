import java.util.*;

class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int res = Integer.MIN_VALUE;
        for (int left = 0; left < n; left++) {
            int[] rowSum = new int[m];
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) rowSum[i] += matrix[i][right];
                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                int prefix = 0;
                for (int s : rowSum) {
                    prefix += s;
                    Integer ceil = set.ceiling(prefix - k);
                    if (ceil != null) res = Math.max(res, prefix - ceil);
                    set.add(prefix);
                }
            }
        }
        return res;
    }
}
