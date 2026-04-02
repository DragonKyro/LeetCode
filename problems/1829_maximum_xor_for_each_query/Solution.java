class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int xorSum = 0;
        for (int x : nums) xorSum ^= x;
        int mask = (1 << maximumBit) - 1;
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            result[i] = xorSum ^ mask;
            xorSum ^= nums[nums.length - 1 - i];
        }
        return result;
    }
}
