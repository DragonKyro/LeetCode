import java.util.*;

class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        Arrays.sort(nums);
        int m = nums.length / 2;
        long ops = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i <= m && nums[i] > k) ops += nums[i] - k;
            else if (i >= m && nums[i] < k) ops += k - nums[i];
        }
        return ops;
    }
}
