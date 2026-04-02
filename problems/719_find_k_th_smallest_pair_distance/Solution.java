import java.util.*;

class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int lo = 0, hi = nums[nums.length - 1] - nums[0];
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.length; right++) {
                while (nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
