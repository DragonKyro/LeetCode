class Solution {
    static final int MOD = 1337;
    public int superPow(int a, int[] b) {
        int result = 1;
        for (int digit : b)
            result = powmod(result, 10) * powmod(a, digit) % MOD;
        return result;
    }
    int powmod(int base, int exp) {
        base %= MOD;
        int result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) result = result * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }
}
