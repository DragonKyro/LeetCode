from typing import List


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        import heapq, math
        heap = [-g for g in gifts]
        heapq.heapify(heap)
        for _ in range(k):
            val = -heapq.heappop(heap)
            heapq.heappush(heap, -int(math.isqrt(val)))
        return -sum(heap)
