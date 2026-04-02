class Solution {
    public int monkeyMove(int n) {
        long MOD = 1_000_000_007;
        return (int)((pow(2, n, MOD) - 2 + MOD) % MOD);
    }
    long pow(long b, int e, long m) { long r=1; b%=m; while(e>0){if((e&1)==1)r=r*b%m;b=b*b%m;e>>=1;} return r; }
}
