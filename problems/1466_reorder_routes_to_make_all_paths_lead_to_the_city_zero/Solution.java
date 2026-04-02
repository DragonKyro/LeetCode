import java.util.*;

class Solution {
    public int minReorder(int n, int[][] connections) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] c : connections) {
            graph.get(c[0]).add(new int[]{c[1], 1});
            graph.get(c[1]).add(new int[]{c[0], 0});
        }
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        visited[0] = true;
        int count = 0;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int[] next : graph.get(node)) {
                if (!visited[next[0]]) {
                    visited[next[0]] = true;
                    count += next[1];
                    queue.offer(next[0]);
                }
            }
        }
        return count;
    }
}
