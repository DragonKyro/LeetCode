class Solution:
    def findTheCity(self, n: int, edges: list[list[int]], distanceThreshold: int) -> int:
        dist = [[float('inf')] * n for _ in range(n)]
        for i in range(n):
            dist[i][i] = 0
        for u, v, w in edges:
            dist[u][v] = w
            dist[v][u] = w
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        res = -1
        min_count = float('inf')
        for i in range(n):
            count = sum(1 for j in range(n) if j != i and dist[i][j] <= distanceThreshold)
            if count <= min_count:
                min_count = count
                res = i
        return res
