import java.util.*;

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int a : answers) count.merge(a, 1, Integer::sum);
        int result = 0;
        for (var entry : count.entrySet()) {
            int k = entry.getKey(), v = entry.getValue();
            result += (v + k) / (k + 1) * (k + 1);
        }
        return result;
    }
}
