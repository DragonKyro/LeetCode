from typing import List


class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        import heapq
        from collections import defaultdict
        MOD = 10**9 + 7
        graph = defaultdict(list)
        for u, v, t in roads:
            graph[u].append((v, t))
            graph[v].append((u, t))
        dist = [float('inf')] * n
        ways = [0] * n
        dist[0] = 0
        ways[0] = 1
        pq = [(0, 0)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, t in graph[u]:
                if d + t < dist[v]:
                    dist[v] = d + t
                    ways[v] = ways[u]
                    heapq.heappush(pq, (dist[v], v))
                elif d + t == dist[v]:
                    ways[v] = (ways[v] + ways[u]) % MOD
        return ways[n - 1] % MOD
