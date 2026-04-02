import java.util.*;

class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        for (int r = 0; r < 4; r++) {
            if (Arrays.deepEquals(mat, target)) return true;
            mat = rotate(mat);
        }
        return false;
    }
    private int[][] rotate(int[][] m) {
        int n = m.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = m[n - 1 - j][i];
        return res;
    }
}
