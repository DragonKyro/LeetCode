import java.util.*;

class Solution {
    List<List<Integer>> graph;
    int[] count, ans;
    int n;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        this.n = n;
        graph = new ArrayList<>();
        count = new int[n]; ans = new int[n];
        Arrays.fill(count, 1);
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) { graph.get(e[0]).add(e[1]); graph.get(e[1]).add(e[0]); }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
    void dfs(int node, int parent) {
        for (int child : graph.get(node)) if (child != parent) {
            dfs(child, node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }
    void dfs2(int node, int parent) {
        for (int child : graph.get(node)) if (child != parent) {
            ans[child] = ans[node] - count[child] + (n - count[child]);
            dfs2(child, node);
        }
    }
}
