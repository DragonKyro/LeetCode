import java.util.*;

class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer,Integer> cnt = new HashMap<>();
        long pairs = 0, ans = 0;
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            pairs += cnt.getOrDefault(nums[i], 0);
            cnt.merge(nums[i], 1, Integer::sum);
            while (pairs >= k) {
                cnt.merge(nums[j], -1, Integer::sum);
                pairs -= cnt.get(nums[j]);
                j++;
            }
            ans += j;
        }
        return ans;
    }
}
