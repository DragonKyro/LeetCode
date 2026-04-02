class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int[] result = new int[2];
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int left = i > 0 ? nums[i - 1] : Integer.MAX_VALUE;
            int right = i < n - 1 ? nums[i + 1] : Integer.MAX_VALUE;
            int diff = nums[i] - Math.min(left, right) + 1;
            if (diff > 0) result[i % 2] += diff;
        }
        return Math.min(result[0], result[1]);
    }
}
