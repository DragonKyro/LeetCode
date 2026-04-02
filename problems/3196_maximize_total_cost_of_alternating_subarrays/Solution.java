class Solution {
    public long maximumTotalCost(int[] nums) {
        long pos = nums[0], neg = Long.MIN_VALUE / 2;
        for (int i = 1; i < nums.length; i++) {
            long np = Math.max(pos, neg) + nums[i];
            long nn = pos - nums[i];
            pos = np; neg = nn;
        }
        return Math.max(pos, neg);
    }
}
