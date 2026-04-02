class Solution {
    public boolean canBeIncreasing(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            boolean valid = true;
            int prev = -1;
            for (int j = 0; j < nums.length; j++) {
                if (j == i) continue;
                if (nums[j] <= prev) { valid = false; break; }
                prev = nums[j];
            }
            if (valid) return true;
        }
        return false;
    }
}
