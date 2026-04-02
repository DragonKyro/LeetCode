class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long res = 0, cur = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] != nums[i - 1]) cur++;
            else cur = 1;
            res += cur;
        }
        return res;
    }
}
