import java.util.*;

class Solution {
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    long dx = bombs[i][0] - bombs[j][0];
                    long dy = bombs[i][1] - bombs[j][1];
                    if (dx * dx + dy * dy <= (long)bombs[i][2] * bombs[i][2])
                        graph.get(i).add(j);
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            boolean[] visited = new boolean[n];
            Queue<Integer> queue = new LinkedList<>();
            queue.add(i); visited[i] = true;
            int count = 0;
            while (!queue.isEmpty()) {
                int node = queue.poll(); count++;
                for (int nei : graph.get(node)) {
                    if (!visited[nei]) { visited[nei] = true; queue.add(nei); }
                }
            }
            max = Math.max(max, count);
        }
        return max;
    }
}
