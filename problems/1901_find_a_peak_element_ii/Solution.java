class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int lo = 0, hi = m - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int maxCol = 0;
            for (int j = 1; j < n; j++) if (mat[mid][j] > mat[mid][maxCol]) maxCol = j;
            int above = mid > 0 ? mat[mid - 1][maxCol] : -1;
            int below = mid < m - 1 ? mat[mid + 1][maxCol] : -1;
            if (mat[mid][maxCol] > above && mat[mid][maxCol] > below) return new int[]{mid, maxCol};
            else if (above > mat[mid][maxCol]) hi = mid - 1;
            else lo = mid + 1;
        }
        return new int[]{-1, -1};
    }
}
