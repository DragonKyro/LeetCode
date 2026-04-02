class Solution {
    public int arrayNesting(int[] nums) {
        int maxLen = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == -1) continue;
            int count = 0, j = i;
            while (nums[j] != -1) {
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
                count++;
            }
            maxLen = Math.max(maxLen, count);
        }
        return maxLen;
    }
}
