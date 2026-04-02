import java.util.*;

class Solution {
    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 0, j = 0;
        for (int i = 0; i < nums.length; i++) {
            while (nums[i]-nums[j] > 2*k) j++;
            ans = Math.max(ans, i-j+1);
        }
        return ans;
    }
}
