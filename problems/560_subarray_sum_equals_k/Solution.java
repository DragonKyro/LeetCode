import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int res = 0, prefix = 0;
        for (int num : nums) {
            prefix += num;
            res += map.getOrDefault(prefix - k, 0);
            map.merge(prefix, 1, Integer::sum);
        }
        return res;
    }
}
