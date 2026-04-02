class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] best = {0, 0};
        for (int i = 0; i < mat.length; i++) {
            int cnt = 0; for (int v : mat[i]) cnt += v;
            if (cnt > best[1]) best = new int[]{i, cnt};
        }
        return best;
    }
}
