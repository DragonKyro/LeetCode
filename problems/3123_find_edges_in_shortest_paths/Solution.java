import java.util.*;

class Solution {
    public boolean[] findAnswer(int n, int[][] edges) {
        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int i = 0; i < edges.length; i++) {
            g[edges[i][0]].add(new int[]{edges[i][1], edges[i][2], i});
            g[edges[i][1]].add(new int[]{edges[i][0], edges[i][2], i});
        }
        long[] d0 = dijkstra(g, 0, n), dn = dijkstra(g, n-1, n);
        boolean[] res = new boolean[edges.length];
        if (d0[n-1] == Long.MAX_VALUE) return res;
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (d0[u] + w + dn[v] == d0[n-1] || d0[v] + w + dn[u] == d0[n-1])
                res[i] = true;
        }
        return res;
    }
    long[] dijkstra(List<int[]>[] g, int src, int n) {
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[src] = 0;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> Long.compare(a[0],b[0]));
        pq.offer(new long[]{0, src});
        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            if (cur[0] > dist[(int)cur[1]]) continue;
            for (int[] e : g[(int)cur[1]]) {
                long nd = cur[0] + e[1];
                if (nd < dist[e[0]]) { dist[e[0]] = nd; pq.offer(new long[]{nd, e[0]}); }
            }
        }
        return dist;
    }
}
