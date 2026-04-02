import java.util.*;

class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) { adj[e[0]].add(e[1]); adj[e[1]].add(e[0]); }
        boolean[] vis = new boolean[n]; int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                List<Integer> nodes = new ArrayList<>();
                Queue<Integer> q = new LinkedList<>(); q.offer(i); vis[i]=true;
                while (!q.isEmpty()) { int u=q.poll(); nodes.add(u); for (int v:adj[u]) if (!vis[v]){vis[v]=true;q.offer(v);} }
                int k = nodes.size(), ec = 0;
                for (int u : nodes) ec += adj[u].size();
                if (ec/2 == k*(k-1)/2) ans++;
            }
        }
        return ans;
    }
}
