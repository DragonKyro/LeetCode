import java.util.*;

class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int total = 0;
        for (int n : nums) total += n;
        List<Integer> res = new ArrayList<>();
        int cur = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            cur += nums[i];
            res.add(nums[i]);
            if (cur > total - cur) break;
        }
        return res;
    }
}
