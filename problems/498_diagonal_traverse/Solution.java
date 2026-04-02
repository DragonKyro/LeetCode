class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] result = new int[m * n];
        int r = 0, c = 0, idx = 0;
        boolean goingUp = true;
        while (idx < m * n) {
            result[idx++] = mat[r][c];
            if (goingUp) {
                if (c == n - 1) { r++; goingUp = false; }
                else if (r == 0) { c++; goingUp = false; }
                else { r--; c++; }
            } else {
                if (r == m - 1) { c++; goingUp = true; }
                else if (c == 0) { r++; goingUp = true; }
                else { r++; c--; }
            }
        }
        return result;
    }
}
