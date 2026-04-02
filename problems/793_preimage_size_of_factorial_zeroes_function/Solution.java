class Solution {
    public int preimageSizeFZF(int k) {
        return (int)(lowerBound(k + 1) - lowerBound(k));
    }

    private long lowerBound(int target) {
        long lo = 0, hi = 5L * (target + 1);
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (countZeros(mid) < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    private long countZeros(long n) {
        long count = 0;
        for (long d = 5; d <= n; d *= 5) count += n / d;
        return count;
    }
}
