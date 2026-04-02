class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] hor = new int[m][n], ver = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    hor[i][j] = j > 0 ? hor[i][j - 1] + 1 : 1;
                    ver[i][j] = i > 0 ? ver[i - 1][j] + 1 : 1;
                }
            }
        }
        int result = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int side = Math.min(hor[i][j], ver[i][j]);
                while (side > result) {
                    if (ver[i][j - side + 1] >= side && hor[i - side + 1][j] >= side) {
                        result = side;
                        break;
                    }
                    side--;
                }
            }
        }
        return result * result;
    }
}
