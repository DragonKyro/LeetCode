import java.util.*;

class Solution {
    public int countKDifference(int[] nums, int k) {
        int count = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            count += freq.getOrDefault(num - k, 0);
            count += freq.getOrDefault(num + k, 0);
            freq.merge(num, 1, Integer::sum);
        }
        return count;
    }
}
