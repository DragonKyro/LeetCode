class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        long total = 0, f = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            f += (long)i * nums[i];
        }
        long res = f;
        for (int i = 1; i < n; i++) {
            f = f + total - (long)n * nums[n - i];
            res = Math.max(res, f);
        }
        return (int)res;
    }
}
