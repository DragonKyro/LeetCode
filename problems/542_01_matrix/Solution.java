import java.util.*;

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] dist = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) queue.offer(new int[]{i, j});
                else dist[i][j] = Integer.MAX_VALUE;
            }
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            for (int[] d : dirs) {
                int nx = cell[0] + d[0], ny = cell[1] + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[cell[0]][cell[1]] + 1) {
                    dist[nx][ny] = dist[cell[0]][cell[1]] + 1;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }
        return dist;
    }
}
