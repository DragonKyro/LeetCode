class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long MOD = 1_000_000_007;
        long total = 0;
        for (int x : arr) total += x;
        long oneMax = kadane(arr);
        if (k == 1) return (int)(oneMax % MOD);
        long twoMax = kadane2(arr);
        if (total > 0) return (int)((twoMax + (k - 2) * total % MOD) % MOD);
        return (int)(twoMax % MOD);
    }
    private long kadane(int[] arr) {
        long max = 0, curr = 0;
        for (int x : arr) {
            curr = Math.max(0, curr + x);
            max = Math.max(max, curr);
        }
        return max;
    }
    private long kadane2(int[] arr) {
        long max = 0, curr = 0;
        for (int t = 0; t < 2; t++)
            for (int x : arr) {
                curr = Math.max(0, curr + x);
                max = Math.max(max, curr);
            }
        return max;
    }
}
