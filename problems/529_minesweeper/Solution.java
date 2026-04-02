class Solution {
    int[][] dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    public char[][] updateBoard(char[][] board, int[] click) {
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') { board[r][c] = 'X'; return board; }
        dfs(board, r, c);
        return board;
    }
    private void dfs(char[][] board, int i, int j) {
        int mines = 0;
        for (int[] d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < board.length && nj >= 0 && nj < board[0].length && board[ni][nj] == 'M') mines++;
        }
        if (mines > 0) { board[i][j] = (char)('0' + mines); return; }
        board[i][j] = 'B';
        for (int[] d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < board.length && nj >= 0 && nj < board[0].length && board[ni][nj] == 'E') dfs(board, ni, nj);
        }
    }
}
