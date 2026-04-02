import java.util.*;

class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        boolean[][] visited = new boolean[n][n];
        pq.offer(new int[]{grid[0][0], 0, 0}); visited[0][0] = true;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int t = cur[0], r = cur[1], c = cur[2];
            if (r == n-1 && c == n-1) return t;
            for (int[] d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.offer(new int[]{Math.max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
}
