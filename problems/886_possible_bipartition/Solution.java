import java.util.*;

class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        for (int[] d : dislikes) { graph.get(d[0]).add(d[1]); graph.get(d[1]).add(d[0]); }
        int[] color = new int[n + 1];
        Arrays.fill(color, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] != -1) continue;
            Queue<Integer> queue = new LinkedList<>();
            queue.add(i); color[i] = 0;
            while (!queue.isEmpty()) {
                int u = queue.poll();
                for (int v : graph.get(u)) {
                    if (color[v] == -1) { color[v] = 1 - color[u]; queue.add(v); }
                    else if (color[v] == color[u]) return false;
                }
            }
        }
        return true;
    }
}
