class Solution:
    def colorBorder(self, grid: list[list[int]], row: int, col: int, color: int) -> list[list[int]]:
        m, n = len(grid), len(grid[0])
        original = grid[row][col]
        visited = set()
        borders = []
        def dfs(i: int, j: int) -> None:
            if (i, j) in visited:
                return
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != original:
                return
            visited.add((i, j))
            if i == 0 or i == m-1 or j == 0 or j == n-1 or \
               grid[i-1][j] != original or grid[i+1][j] != original or \
               grid[i][j-1] != original or grid[i][j+1] != original:
                borders.append((i, j))
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
        dfs(row, col)
        for i, j in borders:
            grid[i][j] = color
        return grid
