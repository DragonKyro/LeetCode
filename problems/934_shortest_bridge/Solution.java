import java.util.*;

class Solution {
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        boolean[][] visited = new boolean[n][n];
        Queue<int[]> queue = new LinkedList<>();
        boolean found = false;
        for (int i = 0; i < n && !found; i++)
            for (int j = 0; j < n && !found; j++)
                if (grid[i][j] == 1) { dfs(grid, visited, queue, i, j, n); found = true; }
        int steps = 0;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int k = 0; k < size; k++) {
                int[] curr = queue.poll();
                for (int[] d : dirs) {
                    int nx = curr[0] + d[0], ny = curr[1] + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                        if (grid[nx][ny] == 1) return steps;
                        visited[nx][ny] = true;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    private void dfs(int[][] grid, boolean[][] visited, Queue<int[]> queue, int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) return;
        visited[i][j] = true;
        queue.offer(new int[]{i, j});
        dfs(grid, visited, queue, i+1, j, n);
        dfs(grid, visited, queue, i-1, j, n);
        dfs(grid, visited, queue, i, j+1, n);
        dfs(grid, visited, queue, i, j-1, n);
    }
}
