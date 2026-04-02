from typing import List


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        def get_pos(s: int) -> tuple:
            r = (s - 1) // n
            c = (s - 1) % n
            if r % 2 == 1:
                c = n - 1 - c
            return n - 1 - r, c
        visited = set()
        queue = deque([(1, 0)])
        visited.add(1)
        while queue:
            curr, moves = queue.popleft()
            for i in range(1, 7):
                nxt = curr + i
                if nxt > n * n:
                    break
                r, c = get_pos(nxt)
                if board[r][c] != -1:
                    nxt = board[r][c]
                if nxt == n * n:
                    return moves + 1
                if nxt not in visited:
                    visited.add(nxt)
                    queue.append((nxt, moves + 1))
        return -1
