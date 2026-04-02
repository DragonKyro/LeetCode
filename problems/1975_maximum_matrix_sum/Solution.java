class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long total = 0;
        int minAbs = Integer.MAX_VALUE, negCount = 0;
        for (int[] row : matrix) {
            for (int x : row) {
                total += Math.abs(x);
                minAbs = Math.min(minAbs, Math.abs(x));
                if (x < 0) negCount++;
            }
        }
        if (negCount % 2 == 1) total -= 2 * minAbs;
        return total;
    }
}
