class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int result = 0;
        int[][] dirs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (int[] d : dirs) {
            int minVal = Integer.MAX_VALUE, maxVal = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                int val = d[0] * arr1[i] + d[1] * arr2[i] + i;
                minVal = Math.min(minVal, val);
                maxVal = Math.max(maxVal, val);
            }
            result = Math.max(result, maxVal - minVal);
        }
        return result;
    }
}
