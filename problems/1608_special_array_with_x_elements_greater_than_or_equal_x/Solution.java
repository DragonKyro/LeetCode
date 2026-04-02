import java.util.*;

class Solution {
    public int specialArray(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        for (int x = 1; x <= n; x++) {
            if (nums[n - x] >= x && (x == n || nums[n - x - 1] < x)) {
                return x;
            }
        }
        return -1;
    }
}
