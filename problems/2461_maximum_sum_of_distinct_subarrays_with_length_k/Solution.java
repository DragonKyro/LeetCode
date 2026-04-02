import java.util.*;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        long windowSum = 0, result = 0;
        for (int i = 0; i < nums.length; i++) {
            windowSum += nums[i];
            count.merge(nums[i], 1, Integer::sum);
            if (i >= k) {
                windowSum -= nums[i - k];
                count.merge(nums[i - k], -1, Integer::sum);
                if (count.get(nums[i - k]) == 0) count.remove(nums[i - k]);
            }
            if (i >= k - 1 && count.size() == k) result = Math.max(result, windowSum);
        }
        return result;
    }
}
