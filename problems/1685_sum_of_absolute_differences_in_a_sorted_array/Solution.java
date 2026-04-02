class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int total = 0;
        for (int num : nums) total += num;
        int[] result = new int[n];
        int prefix = 0;
        for (int i = 0; i < n; i++) {
            int leftSum = prefix;
            int rightSum = total - prefix - nums[i];
            result[i] = nums[i] * i - leftSum + rightSum - nums[i] * (n - i - 1);
            prefix += nums[i];
        }
        return result;
    }
}
