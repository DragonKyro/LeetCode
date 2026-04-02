class Solution {
    public int captureForts(int[] forts) {
        int ans = 0, prev = -1;
        for (int i = 0; i < forts.length; i++) {
            if (forts[i] != 0) {
                if (prev >= 0 && forts[prev] != forts[i]) ans = Math.max(ans, i - prev - 1);
                prev = i;
            }
        }
        return ans;
    }
}
