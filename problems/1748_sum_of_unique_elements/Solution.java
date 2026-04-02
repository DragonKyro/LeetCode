import java.util.*;

class Solution {
    public int sumOfUnique(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) count.merge(num, 1, Integer::sum);
        int sum = 0;
        for (var entry : count.entrySet()) {
            if (entry.getValue() == 1) sum += entry.getKey();
        }
        return sum;
    }
}
