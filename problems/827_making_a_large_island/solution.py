from typing import List


class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        island_id = 2
        sizes = {0: 0}
        def dfs(r: int, c: int, idx: int):
            if r < 0 or r >= n or c < 0 or c >= n or grid[r][c] != 1:
                return 0
            grid[r][c] = idx
            return 1 + dfs(r+1,c,idx) + dfs(r-1,c,idx) + dfs(r,c+1,idx) + dfs(r,c-1,idx)
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 1:
                    sizes[island_id] = dfs(r, c, island_id)
                    island_id += 1
        result = max(sizes.values()) if sizes else 0
        for r in range(n):
            for c in range(n):
                if grid[r][c] == 0:
                    seen = set()
                    total = 1
                    for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                        nr, nc = r+dr, c+dc
                        if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] not in seen:
                            seen.add(grid[nr][nc])
                            total += sizes.get(grid[nr][nc], 0)
                    result = max(result, total)
        return result
