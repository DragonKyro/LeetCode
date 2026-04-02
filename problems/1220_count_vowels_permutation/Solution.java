class Solution {
    public int countVowelPermutation(int n) {
        long MOD = 1_000_000_007;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 1; k < n; k++) {
            long na = e, ne = (a + i) % MOD, ni = (a + e + o + u) % MOD, no = (i + u) % MOD, nu = a;
            a = na; e = ne; i = ni; o = no; u = nu;
        }
        return (int) ((a + e + i + o + u) % MOD);
    }
}
