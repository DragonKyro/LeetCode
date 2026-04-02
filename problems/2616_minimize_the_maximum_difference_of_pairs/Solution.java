import java.util.*;

class Solution {
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int lo = 0, hi = nums[nums.length-1] - nums[0];
        while (lo < hi) {
            int mid = (lo+hi)/2, cnt = 0;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i]-nums[i-1] <= mid) { cnt++; i++; }
            }
            if (cnt >= p) hi = mid; else lo = mid+1;
        }
        return lo;
    }
}
