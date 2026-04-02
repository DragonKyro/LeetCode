class Solution {
    public int maximizeSum(int[] nums, int k) {
        int m = 0; for (int n : nums) m = Math.max(m, n);
        return k * m + k * (k-1) / 2;
    }
}
