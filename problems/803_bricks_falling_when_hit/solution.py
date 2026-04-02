from typing import List


class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        parent = list(range(m * n + 1))
        size = [1] * (m * n + 1)
        def find(x: int) -> int:
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(x: int, y: int):
            px, py = find(x), find(y)
            if px == py: return
            if size[px] < size[py]: px, py = py, px
            parent[py] = px
            size[px] += size[py]
        def index(r: int, c: int) -> int:
            return r * n + c
        TOP = m * n
        grid_copy = [row[:] for row in grid]
        for r, c in hits:
            grid_copy[r][c] = 0
        for c in range(n):
            if grid_copy[0][c] == 1:
                union(index(0, c), TOP)
        for r in range(1, m):
            for c in range(n):
                if grid_copy[r][c] == 0: continue
                if grid_copy[r - 1][c] == 1:
                    union(index(r, c), index(r - 1, c))
                if c > 0 and grid_copy[r][c - 1] == 1:
                    union(index(r, c), index(r, c - 1))
        result = [0] * len(hits)
        for k in range(len(hits) - 1, -1, -1):
            r, c = hits[k]
            if grid[r][c] == 0:
                continue
            prev = size[find(TOP)]
            if r == 0:
                union(index(r, c), TOP)
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid_copy[nr][nc] == 1:
                    union(index(r, c), index(nr, nc))
            grid_copy[r][c] = 1
            result[k] = max(0, size[find(TOP)] - prev - 1)
        return result
