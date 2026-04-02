import java.util.*;

class Solution {
    public int longestWPI(int[] hours) {
        int score = 0, result = 0;
        Map<Integer, Integer> first = new HashMap<>();
        for (int i = 0; i < hours.length; i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                result = i + 1;
            } else {
                first.putIfAbsent(score, i);
                if (first.containsKey(score - 1)) {
                    result = Math.max(result, i - first.get(score - 1));
                }
            }
        }
        return result;
    }
}
