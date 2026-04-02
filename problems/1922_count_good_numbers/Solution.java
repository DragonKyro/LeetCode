class Solution {
    public int countGoodNumbers(long n) {
        long MOD = 1000000007;
        long even = (n + 1) / 2;
        long odd = n / 2;
        return (int) (power(5, even, MOD) * power(4, odd, MOD) % MOD);
    }
    private long power(long base, long exp, long mod) {
        long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = result * base % mod;
            exp /= 2;
            base = base * base % mod;
        }
        return result;
    }
}
