from typing import List


class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        visited = [[False] * n for _ in range(n)]
        queue: deque = deque()
        found = False
        for i in range(n):
            if found:
                break
            for j in range(n):
                if grid[i][j] == 1:
                    self._dfs(grid, visited, queue, i, j, n)
                    found = True
                    break
        steps = 0
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while queue:
            for _ in range(len(queue)):
                x, y = queue.popleft()
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                        if grid[nx][ny] == 1:
                            return steps
                        visited[nx][ny] = True
                        queue.append((nx, ny))
            steps += 1
        return -1

    def _dfs(self, grid: List[List[int]], visited: List[List[bool]], queue: deque, i: int, j: int, n: int) -> None:
        if i < 0 or i >= n or j < 0 or j >= n or visited[i][j] or grid[i][j] == 0:
            return
        visited[i][j] = True
        queue.append((i, j))
        self._dfs(grid, visited, queue, i + 1, j, n)
        self._dfs(grid, visited, queue, i - 1, j, n)
        self._dfs(grid, visited, queue, i, j + 1, n)
        self._dfs(grid, visited, queue, i, j - 1, n)
