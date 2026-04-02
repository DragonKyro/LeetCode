class Solution {
    public boolean checkValidGrid(int[][] grid) {
        int n = grid.length;
        int[][] pos = new int[n*n][2];
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) pos[grid[r][c]] = new int[]{r,c};
        if (pos[0][0]!=0||pos[0][1]!=0) return false;
        for (int i = 1; i < n*n; i++) {
            int dr = Math.abs(pos[i][0]-pos[i-1][0]), dc = Math.abs(pos[i][1]-pos[i-1][1]);
            if (!((dr==1&&dc==2)||(dr==2&&dc==1))) return false;
        }
        return true;
    }
}
