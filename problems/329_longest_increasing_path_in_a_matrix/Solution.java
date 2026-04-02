class Solution {
    int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int[][] memo;
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        memo = new int[m][n];
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = Math.max(res, dfs(matrix, i, j, m, n));
        return res;
    }
    int dfs(int[][] mat, int i, int j, int m, int n) {
        if (memo[i][j] != 0) return memo[i][j];
        int best = 1;
        for (int[] d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] > mat[i][j])
                best = Math.max(best, 1 + dfs(mat, ni, nj, m, n));
        }
        memo[i][j] = best;
        return best;
    }
}
