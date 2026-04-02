class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        for (int t = 0; t < k; t++) {
            int idx = 0;
            for (int i = 1; i < nums.length; i++)
                if (nums[i] < nums[idx]) idx = i;
            nums[idx] *= multiplier;
        }
        return nums;
    }
}
