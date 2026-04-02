import java.util.*;

class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums) if (n % 2 == 0) count.merge(n, 1, Integer::sum);
        int result = -1, maxFreq = 0;
        for (var e : count.entrySet()) {
            if (e.getValue() > maxFreq || (e.getValue() == maxFreq && e.getKey() < result)) {
                maxFreq = e.getValue(); result = e.getKey();
            }
        }
        return result;
    }
}
