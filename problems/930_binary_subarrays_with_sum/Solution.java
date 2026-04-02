import java.util.*;

class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int prefix = 0, result = 0;
        for (int num : nums) {
            prefix += num;
            result += count.getOrDefault(prefix - goal, 0);
            count.merge(prefix, 1, Integer::sum);
        }
        return result;
    }
}
