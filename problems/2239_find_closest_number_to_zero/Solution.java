class Solution {
    public int findClosestNumber(int[] nums) {
        int res = nums[0];
        for (int n : nums) {
            if (Math.abs(n) < Math.abs(res) || (Math.abs(n) == Math.abs(res) && n > res)) {
                res = n;
            }
        }
        return res;
    }
}
