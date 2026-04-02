import java.util.*;

class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> edgeCount = new HashMap<>();
        for (List<Integer> row : wall) {
            int pos = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                pos += row.get(i);
                edgeCount.merge(pos, 1, Integer::sum);
            }
        }
        int maxEdges = 0;
        for (int v : edgeCount.values()) maxEdges = Math.max(maxEdges, v);
        return wall.size() - maxEdges;
    }
}
