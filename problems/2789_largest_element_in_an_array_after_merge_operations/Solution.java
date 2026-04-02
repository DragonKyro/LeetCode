class Solution {
    public long maxArrayValue(int[] nums) {
        long cur = nums[nums.length-1];
        for (int i = nums.length-2; i >= 0; i--) {
            if (nums[i] <= cur) cur += nums[i];
            else cur = nums[i];
        }
        return cur;
    }
}
