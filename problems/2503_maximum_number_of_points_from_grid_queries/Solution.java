import java.util.*;

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length, n = grid[0].length, k = queries.length;
        Integer[] idx = new Integer[k];
        for (int i = 0; i < k; i++) idx[i] = i;
        Arrays.sort(idx, (a, b) -> queries[a] - queries[b]);
        int[] ans = new int[k];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{grid[0][0], 0, 0});
        boolean[][] vis = new boolean[m][n];
        vis[0][0] = true;
        int count = 0;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i : idx) {
            while (!pq.isEmpty() && pq.peek()[0] < queries[i]) {
                int[] cur = pq.poll(); count++;
                for (int[] d : dirs) {
                    int nr = cur[1]+d[0], nc = cur[2]+d[1];
                    if (nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]) { vis[nr][nc]=true; pq.offer(new int[]{grid[nr][nc],nr,nc}); }
                }
            }
            ans[i] = count;
        }
        return ans;
    }
}
