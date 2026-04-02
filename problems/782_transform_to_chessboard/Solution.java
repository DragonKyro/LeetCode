class Solution {
    public int movesToChessboard(int[][] board) {
        int n = board.length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0) return -1;
        int rowSum = 0, colSum = 0, rowSwaps = 0, colSwaps = 0;
        for (int i = 0; i < n; i++) {
            rowSum += board[0][i];
            colSum += board[i][0];
            if (board[0][i] != i % 2) rowSwaps++;
            if (board[i][0] != i % 2) colSwaps++;
        }
        if (rowSum < n/2 || rowSum > (n+1)/2) return -1;
        if (colSum < n/2 || colSum > (n+1)/2) return -1;
        if (n % 2 == 1) {
            if (rowSwaps % 2 == 1) rowSwaps = n - rowSwaps;
            if (colSwaps % 2 == 1) colSwaps = n - colSwaps;
        } else {
            rowSwaps = Math.min(rowSwaps, n - rowSwaps);
            colSwaps = Math.min(colSwaps, n - colSwaps);
        }
        return (rowSwaps + colSwaps) / 2;
    }
}
