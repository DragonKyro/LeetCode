from typing import List


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        import heapq
        heap = [-n for n in nums]
        heapq.heapify(heap)
        score = 0
        for _ in range(k):
            val = -heapq.heappop(heap)
            score += val
            heapq.heappush(heap, -(-(-val) // 3 + (1 if (-val) % 3 != 0 else 0)))
        return score
