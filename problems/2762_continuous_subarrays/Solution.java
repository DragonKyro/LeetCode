import java.util.*;

class Solution {
    public long continuousSubarrays(int[] nums) {
        long ans = 0;
        int j = 0;
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.merge(nums[i], 1, Integer::sum);
            while (map.lastKey() - map.firstKey() > 2) {
                map.merge(nums[j], -1, Integer::sum);
                if (map.get(nums[j]) == 0) map.remove(nums[j]);
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
}
