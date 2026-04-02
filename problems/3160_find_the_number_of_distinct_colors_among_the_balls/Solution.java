import java.util.*;

class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        Map<Integer,Integer> ballColor = new HashMap<>(), colorCount = new HashMap<>();
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballColor.containsKey(ball)) {
                int old = ballColor.get(ball);
                colorCount.merge(old, -1, Integer::sum);
                if (colorCount.get(old) == 0) colorCount.remove(old);
            }
            ballColor.put(ball, color);
            colorCount.merge(color, 1, Integer::sum);
            res[i] = colorCount.size();
        }
        return res;
    }
}
