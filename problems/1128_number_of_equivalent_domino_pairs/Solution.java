import java.util.*;

class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Integer, Integer> count = new HashMap<>();
        int result = 0;
        for (int[] d : dominoes) {
            int key = Math.min(d[0], d[1]) * 10 + Math.max(d[0], d[1]);
            int c = count.getOrDefault(key, 0);
            result += c;
            count.put(key, c + 1);
        }
        return result;
    }
}
