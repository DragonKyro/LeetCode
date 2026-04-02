class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        if ((long) m * k > bloomDay.length) return -1;
        int lo = Integer.MAX_VALUE, hi = Integer.MIN_VALUE;
        for (int d : bloomDay) { lo = Math.min(lo, d); hi = Math.max(hi, d); }
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(bloomDay, m, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    private boolean canMake(int[] bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;
        for (int b : bloomDay) {
            if (b <= days) { flowers++; if (flowers == k) { bouquets++; flowers = 0; } }
            else flowers = 0;
        }
        return bouquets >= m;
    }
}
