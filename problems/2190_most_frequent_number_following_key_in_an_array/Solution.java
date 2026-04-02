import java.util.*;

class Solution {
    public int mostFrequent(int[] nums, int key) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == key) freq.merge(nums[i + 1], 1, Integer::sum);
        }
        return Collections.max(freq.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
