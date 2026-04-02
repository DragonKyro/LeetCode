class Solution:
    def getMaximumGold(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        def dfs(r: int, c: int) -> int:
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0:
                return 0
            val = grid[r][c]
            grid[r][c] = 0
            best = 0
            for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                best = max(best, dfs(r + dr, c + dc))
            grid[r][c] = val
            return val + best
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    ans = max(ans, dfs(i, j))
        return ans
