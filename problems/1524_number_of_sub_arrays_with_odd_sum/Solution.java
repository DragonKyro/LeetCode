class Solution {
    public int numOfSubarrays(int[] arr) {
        int MOD = 1_000_000_007;
        int odd = 0, even = 1, prefix = 0, res = 0;
        for (int n : arr) {
            prefix += n;
            if (prefix % 2 == 1) { res = (res + even) % MOD; odd++; }
            else { res = (res + odd) % MOD; even++; }
        }
        return res;
    }
}
