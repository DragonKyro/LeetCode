class Solution {
    public int minOperations(int[] nums, int x) {
        int target = -x;
        for (int num : nums) target += num;
        if (target < 0) return -1;
        if (target == 0) return nums.length;
        int n = nums.length, maxLen = -1, currSum = 0, left = 0;
        for (int right = 0; right < n; right++) {
            currSum += nums[right];
            while (currSum > target) currSum -= nums[left++];
            if (currSum == target) maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen == -1 ? -1 : n - maxLen;
    }
}
