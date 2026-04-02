from typing import List


class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        m, n = len(grid1), len(grid1[0])
        def dfs(i: int, j: int) -> bool:
            if i < 0 or i >= m or j < 0 or j >= n or grid2[i][j] == 0:
                return True
            grid2[i][j] = 0
            result = grid1[i][j] == 1
            for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                if not dfs(i + di, j + dj):
                    result = False
            return result
        count = 0
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 1 and dfs(i, j):
                    count += 1
        return count
