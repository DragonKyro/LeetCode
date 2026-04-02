class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        long ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(ab, c);
        long lo = 1, hi = 2_000_000_000L;
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            long cnt = mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if (cnt < n) lo = mid + 1;
            else hi = mid;
        }
        return (int) lo;
    }
    private long gcd(long x, long y) { return y == 0 ? x : gcd(y, x % y); }
    private long lcm(long x, long y) { return x / gcd(x, y) * y; }
}
