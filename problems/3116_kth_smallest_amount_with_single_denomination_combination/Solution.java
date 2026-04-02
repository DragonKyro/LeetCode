class Solution {
    public long findKthSmallest(int[] coins, int k) {
        int n = coins.length;
        long lo = 1, hi = (long) coins[0] * k;
        for (int c : coins) hi = Math.min(hi, (long) c * k);
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (count(coins, mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
    long count(int[] coins, long x) {
        int n = coins.length;
        long total = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long lcm = 1;
            int bits = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    lcm = lcm / gcd(lcm, coins[i]) * coins[i];
                    bits++;
                    if (lcm > x) break;
                }
            }
            if (bits % 2 == 1) total += x / lcm;
            else total -= x / lcm;
        }
        return total;
    }
    long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
}
