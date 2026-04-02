class Solution {
    public int minOperations(int[] nums) {
        int ops = 0, flip = 0;
        for (int x : nums) {
            if ((x ^ (flip & 1)) == 0) { ops++; flip++; }
        }
        return ops;
    }
}
