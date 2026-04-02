from typing import List


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        import heapq
        from collections import defaultdict
        graph = defaultdict(list)
        for i, (a, b) in enumerate(edges):
            graph[a].append((b, succProb[i]))
            graph[b].append((a, succProb[i]))
        dist = [0.0] * n
        dist[start_node] = 1.0
        heap = [(-1.0, start_node)]
        while heap:
            neg_prob, node = heapq.heappop(heap)
            prob = -neg_prob
            if node == end_node:
                return prob
            if prob < dist[node]:
                continue
            for neighbor, edge_prob in graph[node]:
                new_prob = prob * edge_prob
                if new_prob > dist[neighbor]:
                    dist[neighbor] = new_prob
                    heapq.heappush(heap, (-new_prob, neighbor))
        return 0.0
