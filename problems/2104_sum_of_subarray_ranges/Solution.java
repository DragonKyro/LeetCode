class Solution {
    public long subArrayRanges(int[] nums) {
        long result = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int minVal = nums[i], maxVal = nums[i];
            for (int j = i + 1; j < n; j++) {
                minVal = Math.min(minVal, nums[j]);
                maxVal = Math.max(maxVal, nums[j]);
                result += maxVal - minVal;
            }
        }
        return result;
    }
}
