import java.util.*;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        int prefix = 0, count = 0;
        for (int x : nums) {
            prefix += x % 2;
            count += freq.getOrDefault(prefix - k, 0);
            freq.merge(prefix, 1, Integer::sum);
        }
        return count;
    }
}
