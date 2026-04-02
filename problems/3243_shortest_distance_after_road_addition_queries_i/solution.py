from typing import List


class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        from collections import deque
        g = [[] for _ in range(n)]
        for i in range(n - 1):
            g[i].append(i + 1)
        def bfs():
            dist = [-1] * n
            dist[0] = 0
            q = deque([0])
            while q:
                u = q.popleft()
                for v in g[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
            return dist[n - 1]
        res = []
        for u, v in queries:
            g[u].append(v)
            res.append(bfs())
        return res
