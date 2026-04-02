class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        int n = nums.length;
        long[] diff = new long[n];
        for (int i = 0; i < n; i++) diff[i] = target[i] - nums[i];
        long ops = Math.abs(diff[0]);
        for (int i = 1; i < n; i++) {
            if (diff[i] > 0 && diff[i-1] > 0) ops += Math.max(0, diff[i]-diff[i-1]);
            else if (diff[i] < 0 && diff[i-1] < 0) ops += Math.max(0, -diff[i]+diff[i-1]);
            else ops += Math.abs(diff[i]);
        }
        return ops;
    }
}
