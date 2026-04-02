class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        long MOD = 1_000_000_007;
        long lcm = (long) a / gcd(a, b) * b;
        long lo = 1, hi = (long) n * Math.min(a, b);
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            if (mid / a + mid / b - mid / lcm >= n) hi = mid;
            else lo = mid + 1;
        }
        return (int) (lo % MOD);
    }
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
}
