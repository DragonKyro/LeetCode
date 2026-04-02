import java.util.*;

class Solution {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        List<int[]>[] graph = new List[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] e : edges) { graph[e[0]].add(new int[]{e[1], e[2]}); graph[e[1]].add(new int[]{e[0], e[2]}); }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            if (cur[0] > dist[cur[1]]) continue;
            for (int[] nei : graph[cur[1]]) {
                int nd = cur[0] + nei[1] + 1;
                if (nd < dist[nei[0]]) { dist[nei[0]] = nd; pq.add(new int[]{nd, nei[0]}); }
            }
        }
        int result = 0;
        for (int d : dist) if (d <= maxMoves) result++;
        for (int[] e : edges) {
            int a = dist[e[0]] <= maxMoves ? Math.max(0, maxMoves - dist[e[0]]) : 0;
            int b = dist[e[1]] <= maxMoves ? Math.max(0, maxMoves - dist[e[1]]) : 0;
            result += Math.min(a + b, e[2]);
        }
        return result;
    }
}
