class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int count = 0;
        for (int r = 0; r < grid.length - 2; r++)
            for (int c = 0; c < grid[0].length - 2; c++)
                if (isMagic(grid, r, c)) count++;
        return count;
    }
    boolean isMagic(int[][] grid, int r, int c) {
        boolean[] seen = new boolean[10];
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            int v = grid[r+i][c+j];
            if (v < 1 || v > 9 || seen[v]) return false;
            seen[v] = true;
        }
        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2] != 15) return false;
            if (grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i] != 15) return false;
        }
        if (grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] != 15) return false;
        if (grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c] != 15) return false;
        return true;
    }
}
