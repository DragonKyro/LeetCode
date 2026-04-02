class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int n = nums.length, maxSeen = Integer.MIN_VALUE, minSeen = Integer.MAX_VALUE;
        int end = -1, start = 0;
        for (int i = 0; i < n; i++) {
            maxSeen = Math.max(maxSeen, nums[i]);
            if (nums[i] < maxSeen) end = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            minSeen = Math.min(minSeen, nums[i]);
            if (nums[i] > minSeen) start = i;
        }
        return end == -1 ? 0 : end - start + 1;
    }
}
