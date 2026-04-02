from typing import List


class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        all_keys = 0
        start = (0, 0)
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '@':
                    start = (r, c)
                elif grid[r][c].islower():
                    all_keys |= 1 << (ord(grid[r][c]) - ord('a'))
        queue = deque([(start[0], start[1], 0, 0)])
        visited = {(start[0], start[1], 0)}
        while queue:
            r, c, keys, dist = queue.popleft()
            if keys == all_keys:
                return dist
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] != '#':
                    ch = grid[nr][nc]
                    new_keys = keys
                    if ch.islower():
                        new_keys |= 1 << (ord(ch) - ord('a'))
                    elif ch.isupper() and not (keys & (1 << (ord(ch.lower()) - ord('a')))):
                        continue
                    if (nr, nc, new_keys) not in visited:
                        visited.add((nr, nc, new_keys))
                        queue.append((nr, nc, new_keys, dist + 1))
        return -1
