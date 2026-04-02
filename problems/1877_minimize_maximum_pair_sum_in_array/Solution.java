import java.util.*;

class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length, result = 0;
        for (int i = 0; i < n / 2; i++) {
            result = Math.max(result, nums[i] + nums[n - 1 - i]);
        }
        return result;
    }
}
