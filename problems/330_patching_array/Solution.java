class Solution {
    public int minPatches(int[] nums, int n) {
        int patches = 0, i = 0;
        long reach = 0;
        while (reach < n) {
            if (i < nums.length && nums[i] <= reach + 1) {
                reach += nums[i++];
            } else {
                reach += reach + 1;
                patches++;
            }
        }
        return patches;
    }
}
