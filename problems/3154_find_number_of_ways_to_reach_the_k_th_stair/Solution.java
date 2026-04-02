class Solution {
    public int waysToReachStair(int k) {
        int res = 0;
        for (int jump = 0; jump < 32; jump++) {
            long pos = 1L << jump;
            long down = pos - k;
            if (down < 0) continue;
            if (down > jump + 1) break;
            res += comb(jump + 1, (int)down);
        }
        return res;
    }
    long comb(int n, int r) {
        if (r > n || r < 0) return 0;
        long res = 1;
        for (int i = 0; i < r; i++) res = res * (n - i) / (i + 1);
        return res;
    }
}
