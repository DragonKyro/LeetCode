from typing import List


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        import heapq
        heap = [-p for p in piles]
        heapq.heapify(heap)
        for _ in range(k):
            top = -heapq.heappop(heap)
            heapq.heappush(heap, -(top - top // 2))
        return -sum(heap)
