import java.util.*;

class Solution {
    int n;
    public int largestIsland(int[][] grid) {
        n = grid.length;
        int id = 2;
        Map<Integer, Integer> sizes = new HashMap<>();
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++)
            if (grid[r][c] == 1) { sizes.put(id, dfs(grid, r, c, id)); id++; }
        int result = sizes.values().stream().mapToInt(Integer::intValue).max().orElse(0);
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            if (grid[r][c] != 0) continue;
            Set<Integer> seen = new HashSet<>();
            int total = 1;
            for (int[] d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0&&nr<n&&nc>=0&&nc<n&&seen.add(grid[nr][nc]))
                    total += sizes.getOrDefault(grid[nr][nc], 0);
            }
            result = Math.max(result, total);
        }
        return result;
    }
    int dfs(int[][] grid, int r, int c, int id) {
        if (r<0||r>=n||c<0||c>=n||grid[r][c]!=1) return 0;
        grid[r][c] = id;
        return 1 + dfs(grid,r+1,c,id) + dfs(grid,r-1,c,id) + dfs(grid,r,c+1,id) + dfs(grid,r,c-1,id);
    }
}
