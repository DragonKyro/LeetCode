from typing import List


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        empty = 0
        start_r = start_c = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != -1:
                    empty += 1
                if grid[i][j] == 1:
                    start_r, start_c = i, j
        self.result = 0

        def dfs(r: int, c: int, count: int) -> None:
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == -1:
                return
            if grid[r][c] == 2:
                if count == empty:
                    self.result += 1
                return
            grid[r][c] = -1
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                dfs(r + dr, c + dc, count + 1)
            grid[r][c] = 0

        dfs(start_r, start_c, 1)
        return self.result
