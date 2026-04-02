class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int maxSum = 0, minSum = 0, currMax = 0, currMin = 0;
        for (int num : nums) {
            currMax = Math.max(currMax + num, num);
            currMin = Math.min(currMin + num, num);
            maxSum = Math.max(maxSum, currMax);
            minSum = Math.min(minSum, currMin);
        }
        return Math.max(maxSum, -minSum);
    }
}
