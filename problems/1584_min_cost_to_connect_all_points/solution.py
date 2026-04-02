from typing import List


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        import heapq
        n = len(points)
        visited = [False] * n
        heap = [(0, 0)]
        total = 0
        count = 0
        while count < n:
            cost, u = heapq.heappop(heap)
            if visited[u]:
                continue
            visited[u] = True
            total += cost
            count += 1
            for v in range(n):
                if not visited[v]:
                    dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1])
                    heapq.heappush(heap, (dist, v))
        return total
