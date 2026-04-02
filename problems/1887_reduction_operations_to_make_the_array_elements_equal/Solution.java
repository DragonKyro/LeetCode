import java.util.*;

class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int ops = 0, count = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) count++;
            ops += count;
        }
        return ops;
    }
}
