class Solution {
    int[] parent;
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1;
        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        int components = n;
        for (int[] c : connections) {
            int pa = find(c[0]), pb = find(c[1]);
            if (pa != pb) { parent[pa] = pb; components--; }
        }
        return components - 1;
    }
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
}
