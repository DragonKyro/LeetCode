class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] count = new int[nums.length + 1];
        for (int num : nums) count[num]++;
        int dup = 0, miss = 0;
        for (int i = 1; i <= nums.length; i++) {
            if (count[i] == 2) dup = i;
            if (count[i] == 0) miss = i;
        }
        return new int[]{dup, miss};
    }
}
