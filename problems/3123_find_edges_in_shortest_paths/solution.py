from typing import List


class Solution:
    def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
        import heapq
        g = [[] for _ in range(n)]
        for i, (u, v, w) in enumerate(edges):
            g[u].append((v, w, i))
            g[v].append((u, w, i))
        def dijkstra(src):
            dist = [float('inf')] * n
            dist[src] = 0
            pq = [(0, src)]
            while pq:
                d, u = heapq.heappop(pq)
                if d > dist[u]: continue
                for v, w, _ in g[u]:
                    if d + w < dist[v]:
                        dist[v] = d + w
                        heapq.heappush(pq, (dist[v], v))
            return dist
        d0 = dijkstra(0)
        dn = dijkstra(n - 1)
        shortest = d0[n - 1]
        res = [False] * len(edges)
        if shortest == float('inf'):
            return res
        for i, (u, v, w) in enumerate(edges):
            if d0[u] + w + dn[v] == shortest or d0[v] + w + dn[u] == shortest:
                res[i] = True
        return res
