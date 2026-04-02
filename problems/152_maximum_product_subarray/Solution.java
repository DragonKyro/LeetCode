class Solution {
    public int maxProduct(int[] nums) {
        int res = nums[0], curMax = 1, curMin = 1;
        for (int n : nums) {
            int a = n * curMax, b = n * curMin;
            curMax = Math.max(n, Math.max(a, b));
            curMin = Math.min(n, Math.min(a, b));
            res = Math.max(res, curMax);
        }
        return res;
    }
}
