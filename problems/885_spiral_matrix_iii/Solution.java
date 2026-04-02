class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int[][] result = new int[rows * cols][2];
        int[] dr = {0,1,0,-1}, dc = {1,0,-1,0};
        int idx = 0, d = 0, steps = 1, r = rStart, c = cStart;
        result[idx++] = new int[]{r, c};
        while (idx < rows * cols) {
            for (int t = 0; t < 2; t++) {
                for (int s = 0; s < steps; s++) {
                    r += dr[d]; c += dc[d];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) result[idx++] = new int[]{r, c};
                }
                d = (d + 1) % 4;
            }
            steps++;
        }
        return result;
    }
}
