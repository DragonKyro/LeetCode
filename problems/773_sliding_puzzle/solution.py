from typing import List


class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        target = '123450'
        start = ''.join(str(board[i][j]) for i in range(2) for j in range(3))
        if start == target:
            return 0
        moves = {0:[1,3], 1:[0,2,4], 2:[1,5], 3:[0,4], 4:[1,3,5], 5:[2,4]}
        queue = collections.deque([(start, 0)])
        visited = {start}
        while queue:
            state, step = queue.popleft()
            idx = state.index('0')
            for nei in moves[idx]:
                new_state = list(state)
                new_state[idx], new_state[nei] = new_state[nei], new_state[idx]
                new_str = ''.join(new_state)
                if new_str == target:
                    return step + 1
                if new_str not in visited:
                    visited.add(new_str)
                    queue.append((new_str, step + 1))
        return -1
