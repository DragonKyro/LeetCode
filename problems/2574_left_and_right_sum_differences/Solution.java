class Solution {
    public int[] leftRightDifference(int[] nums) {
        int total = 0; for (int n : nums) total += n;
        int left = 0;
        int[] ans = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int right = total - left - nums[i];
            ans[i] = Math.abs(left - right);
            left += nums[i];
        }
        return ans;
    }
}
