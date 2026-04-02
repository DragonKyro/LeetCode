from typing import List


class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        import heapq
        pairs = sorted(zip(nums2, nums1), reverse=True)
        heap = []
        s = 0
        ans = 0
        for min_val, val in pairs:
            heapq.heappush(heap, val)
            s += val
            if len(heap) > k:
                s -= heapq.heappop(heap)
            if len(heap) == k:
                ans = max(ans, s * min_val)
        return ans
