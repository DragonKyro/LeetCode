class Solution {
    public int maximumDifference(int[] nums) {
        int minVal = nums[0], maxDiff = -1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > minVal) maxDiff = Math.max(maxDiff, nums[i] - minVal);
            minVal = Math.min(minVal, nums[i]);
        }
        return maxDiff;
    }
}
