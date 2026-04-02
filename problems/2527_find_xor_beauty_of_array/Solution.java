class Solution {
    public int xorBeauty(int[] nums) {
        int res = 0;
        for (int n : nums) res ^= n;
        return res;
    }
}
