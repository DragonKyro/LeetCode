from typing import List


class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        workers = sorted((w / q, q) for w, q in zip(wage, quality))
        result = float('inf')
        total_quality = 0
        heap = []
        for ratio, q in workers:
            heapq.heappush(heap, -q)
            total_quality += q
            if len(heap) > k:
                total_quality += heapq.heappop(heap)
            if len(heap) == k:
                result = min(result, total_quality * ratio)
        return result
