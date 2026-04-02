class Solution {
    public int minStartValue(int[] nums) {
        int minPrefix = 0, prefix = 0;
        for (int n : nums) {
            prefix += n;
            minPrefix = Math.min(minPrefix, prefix);
        }
        return 1 - minPrefix;
    }
}
