from typing import List


class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        from collections import deque
        import math
        def diameter(edges, n):
            if n == 1: return 0
            g = [[] for _ in range(n)]
            for u, v in edges:
                g[u].append(v)
                g[v].append(u)
            def bfs(start):
                dist = [-1] * n
                dist[start] = 0
                q = deque([start])
                far = start
                while q:
                    u = q.popleft()
                    for v in g[u]:
                        if dist[v] == -1:
                            dist[v] = dist[u] + 1
                            q.append(v)
                            if dist[v] > dist[far]:
                                far = v
                return far, dist[far]
            far1, _ = bfs(0)
            far2, d = bfs(far1)
            return d
        d1 = diameter(edges1, len(edges1) + 1)
        d2 = diameter(edges2, len(edges2) + 1)
        return max(d1, d2, math.ceil(d1 / 2) + math.ceil(d2 / 2) + 1)
