class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] row = new int[m*n+1], col = new int[m*n+1];
        for (int r = 0; r < m; r++) for (int c = 0; c < n; c++) { row[mat[r][c]]=r; col[mat[r][c]]=c; }
        int[] rc = new int[m], cc = new int[n];
        for (int i = 0; i < arr.length; i++) {
            int r = row[arr[i]], c = col[arr[i]];
            rc[r]++; cc[c]++;
            if (rc[r]==n||cc[c]==m) return i;
        }
        return -1;
    }
}
