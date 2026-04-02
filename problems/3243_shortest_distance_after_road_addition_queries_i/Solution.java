import java.util.*;

class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int i = 0; i < n-1; i++) g[i].add(i+1);
        int[] res = new int[queries.length];
        for (int q = 0; q < queries.length; q++) {
            g[queries[q][0]].add(queries[q][1]);
            res[q] = bfs(g, n);
        }
        return res;
    }
    int bfs(List<Integer>[] g, int n) {
        int[] dist = new int[n]; Arrays.fill(dist, -1); dist[0] = 0;
        Queue<Integer> q = new LinkedList<>(); q.add(0);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g[u]) if (dist[v]==-1) { dist[v]=dist[u]+1; q.add(v); }
        }
        return dist[n-1];
    }
}
