from typing import List


class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))
        dist = [float('inf')] * n
        dist[0] = 0
        heap = [(0, 0)]
        while heap:
            d, u = heapq.heappop(heap)
            if d > dist[u]:
                continue
            for v, w in graph[u]:
                nd = d + w + 1
                if nd < dist[v]:
                    dist[v] = nd
                    heapq.heappush(heap, (nd, v))
        result = sum(1 for d in dist if d <= maxMoves)
        for u, v, w in edges:
            a = max(0, maxMoves - dist[u]) if dist[u] <= maxMoves else 0
            b = max(0, maxMoves - dist[v]) if dist[v] <= maxMoves else 0
            result += min(a + b, w)
        return result
