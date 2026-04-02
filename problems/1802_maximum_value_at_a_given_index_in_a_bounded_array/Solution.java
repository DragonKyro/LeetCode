class Solution {
    public int maxValue(int n, int index, int maxSum) {
        int lo = 1, hi = maxSum;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (count(n, index, mid) <= maxSum) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
    private long count(int n, int index, int mid) {
        long total = mid;
        long left = Math.min(mid - 1, index);
        long right = Math.min(mid - 1, n - 1 - index);
        total += left * (left + 1) / 2;
        if (left < index) total += index - left;
        else total -= (left - index) * (left - index + 1) / 2;
        total += right * (right + 1) / 2;
        if (right < n - 1 - index) total += n - 1 - index - right;
        else total -= (right - (n - 1 - index)) * (right - (n - 1 - index) + 1) / 2;
        return total;
    }
}
