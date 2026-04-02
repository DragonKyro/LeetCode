import java.util.*;

class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<Integer>[][] graph = new List[2][n];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = new ArrayList<>();
        for (int[] e : redEdges) graph[0][e[0]].add(e[1]);
        for (int[] e : blueEdges) graph[1][e[0]].add(e[1]);
        int[] result = new int[n];
        Arrays.fill(result, -1);
        boolean[][] visited = new boolean[2][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0});
        queue.offer(new int[]{0, 1, 0});
        visited[0][0] = true;
        visited[1][0] = true;
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int node = curr[0], color = curr[1], dist = curr[2];
            if (result[node] == -1) result[node] = dist;
            int next = 1 - color;
            for (int nei : graph[next][node]) {
                if (!visited[next][nei]) {
                    visited[next][nei] = true;
                    queue.offer(new int[]{nei, next, dist + 1});
                }
            }
        }
        return result;
    }
}
