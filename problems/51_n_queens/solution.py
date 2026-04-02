class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        result = []
        board = ['.' * n for _ in range(n)]
        cols = set()
        diag1 = set()
        diag2 = set()

        def backtrack(row: int) -> None:
            if row == n:
                result.append(board[:])
                return
            for col in range(n):
                if col in cols or (row - col) in diag1 or (row + col) in diag2:
                    continue
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)
                board[row] = '.' * col + 'Q' + '.' * (n - col - 1)
                backtrack(row + 1)
                board[row] = '.' * n
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        backtrack(0)
        return result
