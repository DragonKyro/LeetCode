class Solution {
    int[] parent, size;
    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length, n = grid[0].length;
        parent = new int[m * n + 1];
        size = new int[m * n + 1];
        for (int i = 0; i <= m * n; i++) { parent[i] = i; size[i] = 1; }
        int TOP = m * n;
        int[][] gridCopy = new int[m][n];
        for (int i = 0; i < m; i++) gridCopy[i] = grid[i].clone();
        for (int[] h : hits) gridCopy[h[0]][h[1]] = 0;
        for (int c = 0; c < n; c++) if (gridCopy[0][c] == 1) union(c, TOP);
        for (int r = 1; r < m; r++) for (int c = 0; c < n; c++) {
            if (gridCopy[r][c] == 0) continue;
            if (gridCopy[r - 1][c] == 1) union(r * n + c, (r - 1) * n + c);
            if (c > 0 && gridCopy[r][c - 1] == 1) union(r * n + c, r * n + c - 1);
        }
        int[] result = new int[hits.length];
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int k = hits.length - 1; k >= 0; k--) {
            int r = hits[k][0], c = hits[k][1];
            if (grid[r][c] == 0) continue;
            int prev = size[find(TOP)];
            if (r == 0) union(r * n + c, TOP);
            for (int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && gridCopy[nr][nc] == 1)
                    union(r * n + c, nr * n + nc);
            }
            gridCopy[r][c] = 1;
            result[k] = Math.max(0, size[find(TOP)] - prev - 1);
        }
        return result;
    }
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
    void union(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (size[px] < size[py]) { int t = px; px = py; py = t; }
        parent[py] = px; size[px] += size[py];
    }
}
