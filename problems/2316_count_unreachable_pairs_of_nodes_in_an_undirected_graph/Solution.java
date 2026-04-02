class Solution {
    int[] parent, size;
    public long countPairs(int n, int[][] edges) {
        parent = new int[n]; size = new int[n];
        for (int i = 0; i < n; i++) { parent[i] = i; size[i] = 1; }
        for (int[] e : edges) union(e[0], e[1]);
        long total = 0;
        long remaining = n;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) { remaining -= size[i]; total += (long) size[i] * remaining; }
        }
        return total;
    }
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void union(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (size[px] < size[py]) { int t = px; px = py; py = t; }
        parent[py] = px; size[px] += size[py];
    }
}
