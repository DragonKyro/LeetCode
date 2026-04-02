from typing import List


class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        px = [[0]*(n+1) for _ in range(m+1)]
        py = [[0]*(n+1) for _ in range(m+1)]
        res = 0
        for i in range(m):
            for j in range(n):
                px[i+1][j+1] = px[i][j+1] + px[i+1][j] - px[i][j] + (1 if grid[i][j]=='X' else 0)
                py[i+1][j+1] = py[i][j+1] + py[i+1][j] - py[i][j] + (1 if grid[i][j]=='Y' else 0)
                if px[i+1][j+1] > 0 and px[i+1][j+1] == py[i+1][j+1]:
                    res += 1
        return res
