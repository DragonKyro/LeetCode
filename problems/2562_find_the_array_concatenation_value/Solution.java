class Solution {
    public long findTheArrayConcVal(int[] nums) {
        long val = 0;
        int i = 0, j = nums.length - 1;
        while (i < j) { val += Long.parseLong(nums[i]+""+nums[j]); i++; j--; }
        if (i == j) val += nums[i];
        return val;
    }
}
