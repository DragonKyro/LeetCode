import java.util.*;

class Solution {
    int timer = 0;
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (List<Integer> e : connections) {
            graph[e.get(0)].add(e.get(1));
            graph[e.get(1)].add(e.get(0));
        }
        int[] disc = new int[n], low = new int[n];
        Arrays.fill(disc, -1);
        dfs(0, -1, disc, low, graph);
        return result;
    }
    void dfs(int u, int parent, int[] disc, int[] low, List<Integer>[] graph) {
        disc[u] = low[u] = timer++;
        for (int v : graph[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                dfs(v, u, disc, low, graph);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > disc[u]) result.add(Arrays.asList(u, v));
            } else {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }
}
