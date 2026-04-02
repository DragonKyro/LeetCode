import java.util.*;

class Solution {
    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        List<int[]> borders = new ArrayList<>();
        dfs(grid, row, col, grid[row][col], visited, borders);
        for (int[] b : borders) grid[b[0]][b[1]] = color;
        return grid;
    }
    private void dfs(int[][] grid, int i, int j, int orig, boolean[][] visited, List<int[]> borders) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || visited[i][j] || grid[i][j] != orig) return;
        visited[i][j] = true;
        if (i == 0 || i == grid.length-1 || j == 0 || j == grid[0].length-1 ||
            grid[i-1][j] != orig || grid[i+1][j] != orig || grid[i][j-1] != orig || grid[i][j+1] != orig)
            borders.add(new int[]{i, j});
        dfs(grid, i+1, j, orig, visited, borders);
        dfs(grid, i-1, j, orig, visited, borders);
        dfs(grid, i, j+1, orig, visited, borders);
        dfs(grid, i, j-1, orig, visited, borders);
    }
}
