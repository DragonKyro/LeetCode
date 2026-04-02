import java.util.*;

class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Arrays.sort(nums);
        int i = 0;
        while (k > 0 && i < nums.length && nums[i] < 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        if (k % 2 == 1) {
            Arrays.sort(nums);
            nums[0] = -nums[0];
        }
        int sum = 0;
        for (int n : nums) sum += n;
        return sum;
    }
}
