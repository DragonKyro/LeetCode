import java.util.*;

class NeighborSum {
    int[][] grid;
    int n;
    Map<Integer, int[]> pos = new HashMap<>();
    public NeighborSum(int[][] grid) {
        this.grid = grid; n = grid.length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                pos.put(grid[i][j], new int[]{i, j});
    }
    public int adjacentSum(int value) {
        int[] p = pos.get(value);
        int s = 0;
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int[] d : dirs) {
            int ni = p[0]+d[0], nj = p[1]+d[1];
            if (ni>=0&&ni<n&&nj>=0&&nj<n) s += grid[ni][nj];
        }
        return s;
    }
    public int diagonalSum(int value) {
        int[] p = pos.get(value);
        int s = 0;
        int[][] dirs = {{-1,-1},{-1,1},{1,-1},{1,1}};
        for (int[] d : dirs) {
            int ni = p[0]+d[0], nj = p[1]+d[1];
            if (ni>=0&&ni<n&&nj>=0&&nj<n) s += grid[ni][nj];
        }
        return s;
    }
}
