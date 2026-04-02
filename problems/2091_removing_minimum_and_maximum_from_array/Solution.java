class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length, minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int left = Math.min(minIdx, maxIdx) + 1;
        int right = n - Math.max(minIdx, maxIdx);
        int fromLeft = Math.max(minIdx, maxIdx) + 1;
        int fromRight = n - Math.min(minIdx, maxIdx);
        return Math.min(left + right, Math.min(fromLeft, fromRight));
    }
}
