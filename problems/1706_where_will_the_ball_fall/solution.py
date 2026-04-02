from typing import List


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        result = []
        for col in range(n):
            c = col
            stuck = False
            for row in range(m):
                nc = c + grid[row][c]
                if nc < 0 or nc >= n or grid[row][nc] != grid[row][c]:
                    stuck = True
                    break
                c = nc
            result.append(-1 if stuck else c)
        return result
