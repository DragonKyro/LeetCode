import java.util.*;

class Solution {
    public int cutOffTree(List<List<Integer>> forest) {
        List<int[]> trees = new ArrayList<>();
        for (int i = 0; i < forest.size(); i++)
            for (int j = 0; j < forest.get(0).size(); j++)
                if (forest.get(i).get(j) > 1) trees.add(new int[]{forest.get(i).get(j), i, j});
        trees.sort((a, b) -> a[0] - b[0]);
        int sr = 0, sc = 0, total = 0;
        for (int[] tree : trees) {
            int steps = bfs(forest, sr, sc, tree[1], tree[2]);
            if (steps == -1) return -1;
            total += steps;
            sr = tree[1]; sc = tree[2];
        }
        return total;
    }
    private int bfs(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
        if (sr == tr && sc == tc) return 0;
        int m = forest.size(), n = forest.get(0).size();
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sr, sc, 0});
        visited[sr][sc] = true;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            for (int[] d : dirs) {
                int nr = curr[0] + d[0], nc = curr[1] + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && forest.get(nr).get(nc) > 0) {
                    if (nr == tr && nc == tc) return curr[2] + 1;
                    visited[nr][nc] = true;
                    queue.offer(new int[]{nr, nc, curr[2] + 1});
                }
            }
        }
        return -1;
    }
}
