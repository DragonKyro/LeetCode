import java.util.*;

class Solution {
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = diameter(edges1, edges1.length+1);
        int d2 = diameter(edges2, edges2.length+1);
        return Math.max(Math.max(d1, d2), (d1+1)/2 + (d2+1)/2 + 1);
    }
    int diameter(int[][] edges, int n) {
        if (n == 1) return 0;
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int[] e : edges) { g[e[0]].add(e[1]); g[e[1]].add(e[0]); }
        int[] r1 = bfs(g, 0, n);
        int[] r2 = bfs(g, r1[0], n);
        return r2[1];
    }
    int[] bfs(List<Integer>[] g, int start, int n) {
        int[] dist = new int[n]; Arrays.fill(dist, -1); dist[start] = 0;
        Queue<Integer> q = new LinkedList<>(); q.add(start);
        int far = start;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g[u]) if (dist[v]==-1) {
                dist[v]=dist[u]+1; q.add(v);
                if (dist[v]>dist[far]) far=v;
            }
        }
        return new int[]{far, dist[far]};
    }
}
