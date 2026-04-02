class Solution {
    int[] parent;
    public int[] findRedundantConnection(int[][] edges) {
        parent = new int[edges.length + 1];
        for (int i = 0; i < parent.length; i++) parent[i] = i;
        for (int[] edge : edges) {
            int pu = find(edge[0]), pv = find(edge[1]);
            if (pu == pv) return edge;
            parent[pu] = pv;
        }
        return new int[]{};
    }
    private int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
}
