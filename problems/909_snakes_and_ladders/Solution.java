import java.util.*;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean[] visited = new boolean[n * n + 1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 0});
        visited[1] = true;
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            for (int i = 1; i <= 6; i++) {
                int next = curr[0] + i;
                if (next > n * n) break;
                int r = (next - 1) / n, c = (next - 1) % n;
                if (r % 2 == 1) c = n - 1 - c;
                r = n - 1 - r;
                if (board[r][c] != -1) next = board[r][c];
                if (next == n * n) return curr[1] + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(new int[]{next, curr[1] + 1});
                }
            }
        }
        return -1;
    }
}
