import java.util.*;

class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        return countLess(nums, upper) - countLess(nums, lower - 1);
    }
    long countLess(int[] nums, int target) {
        long cnt = 0;
        int lo = 0, hi = nums.length - 1;
        while (lo < hi) {
            if (nums[lo] + nums[hi] <= target) { cnt += hi - lo; lo++; }
            else hi--;
        }
        return cnt;
    }
}
