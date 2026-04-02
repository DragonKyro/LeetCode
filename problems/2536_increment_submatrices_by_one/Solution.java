class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] mat = new int[n][n+1];
        for (int[] q : queries)
            for (int r = q[0]; r <= q[2]; r++) { mat[r][q[1]]++; if (q[3]+1<n) mat[r][q[3]+1]--; }
        int[][] res = new int[n][n];
        for (int r = 0; r < n; r++) {
            int s = 0;
            for (int c = 0; c < n; c++) { s += mat[r][c]; res[r][c] = s; }
        }
        return res;
    }
}
