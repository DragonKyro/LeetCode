import java.util.*;

class Solution {
    public int countPaths(int n, int[][] roads) {
        long MOD = 1000000007;
        List<long[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] r : roads) { graph[r[0]].add(new long[]{r[1], r[2]}); graph[r[1]].add(new long[]{r[0], r[2]}); }
        long[] dist = new long[n];
        long[] ways = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0; ways[0] = 1;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        pq.offer(new long[]{0, 0});
        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            long d = cur[0]; int u = (int) cur[1];
            if (d > dist[u]) continue;
            for (long[] e : graph[u]) {
                int v = (int) e[0]; long t = e[1];
                if (d + t < dist[v]) { dist[v] = d + t; ways[v] = ways[u]; pq.offer(new long[]{dist[v], v}); }
                else if (d + t == dist[v]) ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return (int) (ways[n - 1] % MOD);
    }
}
