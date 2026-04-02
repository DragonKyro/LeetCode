import java.util.*;

class Solution {
    int res = 0;
    List<Integer>[] g;
    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int[] e : edges) { g[e[0]].add(e[1]); g[e[1]].add(e[0]); }
        dfs(0, -1);
        return res;
    }
    int dfs(int u, int p) {
        List<Integer> sizes = new ArrayList<>();
        int total = 1;
        for (int v : g[u]) {
            if (v != p) { int sz = dfs(v, u); sizes.add(sz); total += sz; }
        }
        if (sizes.isEmpty() || new HashSet<>(sizes).size() == 1) res++;
        return total;
    }
}
