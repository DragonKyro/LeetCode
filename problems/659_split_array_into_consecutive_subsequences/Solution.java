import java.util.*;

class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>(), append = new HashMap<>();
        for (int num : nums) freq.merge(num, 1, Integer::sum);
        for (int num : nums) {
            if (freq.getOrDefault(num, 0) == 0) continue;
            if (append.getOrDefault(num, 0) > 0) {
                append.merge(num, -1, Integer::sum);
                append.merge(num + 1, 1, Integer::sum);
            } else if (freq.getOrDefault(num + 1, 0) > 0 && freq.getOrDefault(num + 2, 0) > 0) {
                freq.merge(num + 1, -1, Integer::sum);
                freq.merge(num + 2, -1, Integer::sum);
                append.merge(num + 3, 1, Integer::sum);
            } else return false;
            freq.merge(num, -1, Integer::sum);
        }
        return true;
    }
}
