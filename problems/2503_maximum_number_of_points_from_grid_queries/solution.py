from typing import List


class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        import heapq
        m, n = len(grid), len(grid[0])
        idx = sorted(range(len(queries)), key=lambda i: queries[i])
        ans = [0] * len(queries)
        heap = [(grid[0][0], 0, 0)]
        visited = [[False] * n for _ in range(m)]
        visited[0][0] = True
        count = 0
        for i in idx:
            q = queries[i]
            while heap and heap[0][0] < q:
                val, r, c = heapq.heappop(heap)
                count += 1
                for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                        visited[nr][nc] = True
                        heapq.heappush(heap, (grid[nr][nc], nr, nc))
            ans[i] = count
        return ans
