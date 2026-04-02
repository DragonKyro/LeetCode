import java.util.*;

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int prefix = 0, result = 0;
        for (int num : nums) {
            prefix = ((prefix + num) % k + k) % k;
            result += count.getOrDefault(prefix, 0);
            count.merge(prefix, 1, Integer::sum);
        }
        return result;
    }
}
