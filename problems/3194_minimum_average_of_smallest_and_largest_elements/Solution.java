import java.util.*;

class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        double res = Double.MAX_VALUE;
        int n = nums.length;
        for (int i = 0; i < n/2; i++)
            res = Math.min(res, (nums[i]+nums[n-1-i]) / 2.0);
        return res;
    }
}
