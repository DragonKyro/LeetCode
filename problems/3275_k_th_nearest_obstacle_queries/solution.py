from typing import List


class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        import heapq
        heap = []
        res = []
        for x, y in queries:
            d = abs(x) + abs(y)
            if len(heap) < k:
                heapq.heappush(heap, -d)
            elif d < -heap[0]:
                heapq.heapreplace(heap, -d)
            res.append(-heap[0] if len(heap) == k else -1)
        return res
