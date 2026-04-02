class Solution {
    static final int MOD = 1_000_000_007;
    public int countAnagrams(String s) {
        long[] fact = new long[100001]; fact[0] = 1;
        for (int i = 1; i <= 100000; i++) fact[i] = fact[i-1]*i%MOD;
        long ans = 1;
        for (String w : s.split(" ")) {
            ans = ans * fact[w.length()] % MOD;
            int[] cnt = new int[26];
            for (char c : w.toCharArray()) cnt[c-'a']++;
            for (int c : cnt) if (c > 0) ans = ans * pow(fact[c], MOD-2) % MOD;
        }
        return (int) ans;
    }
    long pow(long b, long e) { long r=1; b%=MOD; while(e>0){if((e&1)==1)r=r*b%MOD;b=b*b%MOD;e>>=1;} return r; }
}
