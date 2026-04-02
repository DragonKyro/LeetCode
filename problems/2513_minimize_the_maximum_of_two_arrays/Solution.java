class Solution {
    public int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
        long lcm = (long) d1 / gcd(d1, d2) * d2;
        long lo = 1, hi = (long) 2e9;
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            long a = mid - mid/d1, b = mid - mid/d2, c = mid - mid/lcm;
            if (a >= cnt1 && b >= cnt2 && c >= cnt1+cnt2) hi = mid; else lo = mid+1;
        }
        return (int) lo;
    }
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
}
