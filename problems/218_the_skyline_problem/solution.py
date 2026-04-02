from typing import List


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        import heapq
        events = []
        for l, r, h in buildings:
            events.append((l, -h, r))
            events.append((r, 0, 0))
        events.sort()
        res = [[0, 0]]
        heap = [(0, float('inf'))]
        for x, neg_h, r in events:
            while heap[0][1] <= x:
                heapq.heappop(heap)
            if neg_h:
                heapq.heappush(heap, (neg_h, r))
            max_h = -heap[0][0]
            if res[-1][1] != max_h:
                res.append([x, max_h])
        return res[1:]
