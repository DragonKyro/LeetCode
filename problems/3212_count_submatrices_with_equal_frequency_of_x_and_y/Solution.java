class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length, n = grid[0].length, res = 0;
        int[][] px = new int[m+1][n+1], py = new int[m+1][n+1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                px[i+1][j+1] = px[i][j+1]+px[i+1][j]-px[i][j]+(grid[i][j]=='X'?1:0);
                py[i+1][j+1] = py[i][j+1]+py[i+1][j]-py[i][j]+(grid[i][j]=='Y'?1:0);
                if (px[i+1][j+1]>0 && px[i+1][j+1]==py[i+1][j+1]) res++;
            }
        return res;
    }
}
