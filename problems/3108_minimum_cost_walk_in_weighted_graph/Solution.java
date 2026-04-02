class Solution {
    int[] parent, rank, cost;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    void union(int a, int b, int w) {
        int ra = find(a), rb = find(b);
        if (ra == rb) { cost[ra] &= w; return; }
        if (rank[ra] < rank[rb]) { int t=ra; ra=rb; rb=t; }
        parent[rb] = ra;
        cost[ra] = cost[ra] & cost[rb] & w;
        if (rank[ra] == rank[rb]) rank[ra]++;
    }
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        parent = new int[n]; rank = new int[n]; cost = new int[n];
        for (int i = 0; i < n; i++) { parent[i] = i; cost[i] = (1<<30)-1; }
        for (int[] e : edges) union(e[0], e[1], e[2]);
        int[] res = new int[query.length];
        for (int i = 0; i < query.length; i++) {
            if (query[i][0] == query[i][1]) res[i] = 0;
            else if (find(query[i][0]) != find(query[i][1])) res[i] = -1;
            else res[i] = cost[find(query[i][0])];
        }
        return res;
    }
}
