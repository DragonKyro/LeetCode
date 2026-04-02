class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        int[] cand1 = null, cand2 = null;
        for (int[] e : edges) {
            if (parent[e[1]] != 0) {
                cand1 = new int[]{parent[e[1]], e[1]};
                cand2 = new int[]{e[0], e[1]};
                break;
            }
            parent[e[1]] = e[0];
        }
        int[] root = new int[n + 1];
        for (int i = 0; i <= n; i++) root[i] = i;
        for (int[] e : edges) {
            if (cand2 != null && e[0] == cand2[0] && e[1] == cand2[1]) continue;
            int pu = find(root, e[0]), pv = find(root, e[1]);
            if (pu == pv) return cand1 != null ? cand1 : e;
            root[pv] = pu;
        }
        return cand2;
    }
    private int find(int[] root, int x) {
        while (root[x] != x) { root[x] = root[root[x]]; x = root[x]; }
        return x;
    }
}
