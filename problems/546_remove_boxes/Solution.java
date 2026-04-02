class Solution {
    int[][][] memo;
    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        memo = new int[n][n][n];
        return dp(boxes, 0, n - 1, 0);
    }
    private int dp(int[] boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (memo[l][r][k] != 0) return memo[l][r][k];
        int origR = r, origK = k;
        while (r > l && boxes[r] == boxes[r - 1]) { r--; k++; }
        int res = (k + 1) * (k + 1) + dp(boxes, l, r - 1, 0);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r])
                res = Math.max(res, dp(boxes, l, i, k + 1) + dp(boxes, i + 1, r - 1, 0));
        }
        return memo[l][origR][origK] = res;
    }
}
