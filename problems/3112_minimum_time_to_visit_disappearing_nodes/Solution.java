import java.util.*;

class Solution {
    public int[] minimumTime(int n, int[][] edges, int[] disappear) {
        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int[] e : edges) {
            g[e[0]].add(new int[]{e[1], e[2]});
            g[e[1]].add(new int[]{e[0], e[2]});
        }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            if (cur[0] > dist[cur[1]]) continue;
            for (int[] e : g[cur[1]]) {
                int nd = cur[0] + e[1];
                if (nd < dist[e[0]] && nd < disappear[e[0]]) {
                    dist[e[0]] = nd;
                    pq.offer(new int[]{nd, e[0]});
                }
            }
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++) res[i] = dist[i] == Integer.MAX_VALUE ? -1 : dist[i];
        return res;
    }
}
