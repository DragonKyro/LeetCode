import java.util.*;

class Solution {
    private int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        boolean[][] pacific = new boolean[m][n], atlantic = new boolean[m][n];
        for (int i = 0; i < m; i++) { dfs(heights, pacific, i, 0); dfs(heights, atlantic, i, n-1); }
        for (int j = 0; j < n; j++) { dfs(heights, pacific, 0, j); dfs(heights, atlantic, m-1, j); }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j]) result.add(Arrays.asList(i, j));
        return result;
    }
    private void dfs(int[][] heights, boolean[][] visited, int r, int c) {
        visited[r][c] = true;
        for (int[] d : dirs) {
            int nr = r+d[0], nc = c+d[1];
            if (nr>=0 && nr<heights.length && nc>=0 && nc<heights[0].length && !visited[nr][nc] && heights[nr][nc]>=heights[r][c])
                dfs(heights, visited, nr, nc);
        }
    }
}
