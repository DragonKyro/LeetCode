import java.util.*;

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % k != 0) return false;
        int target = sum / k;
        Arrays.sort(nums);
        int[] buckets = new int[k];
        return backtrack(nums, buckets, nums.length - 1, target);
    }
    private boolean backtrack(int[] nums, int[] buckets, int idx, int target) {
        if (idx < 0) return true;
        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i] + nums[idx] <= target) {
                buckets[i] += nums[idx];
                if (backtrack(nums, buckets, idx - 1, target)) return true;
                buckets[i] -= nums[idx];
            }
            if (buckets[i] == 0) break;
        }
        return false;
    }
}
