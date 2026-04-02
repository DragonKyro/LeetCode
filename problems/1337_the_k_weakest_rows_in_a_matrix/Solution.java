import java.util.*;

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int m = mat.length;
        int[][] strengths = new int[m][2];
        for (int i = 0; i < m; i++) {
            strengths[i][0] = 0;
            for (int x : mat[i]) strengths[i][0] += x;
            strengths[i][1] = i;
        }
        Arrays.sort(strengths, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int[] res = new int[k];
        for (int i = 0; i < k; i++) res[i] = strengths[i][1];
        return res;
    }
}
