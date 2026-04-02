class Solution {
    public long countCompleteDayPairs(int[] hours) {
        long[] cnt = new long[24];
        long res = 0;
        for (int h : hours) {
            int r = h % 24;
            res += cnt[(24 - r) % 24];
            cnt[r]++;
        }
        return res;
    }
}
