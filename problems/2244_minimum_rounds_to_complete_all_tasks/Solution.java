import java.util.*;

class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int t : tasks) count.merge(t, 1, Integer::sum);
        int rounds = 0;
        for (int v : count.values()) {
            if (v == 1) return -1;
            rounds += (v + 2) / 3;
        }
        return rounds;
    }
}
