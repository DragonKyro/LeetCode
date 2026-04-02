class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        res = []
        heap = []
        if a: heap.append((-a, 'a'))
        if b: heap.append((-b, 'b'))
        if c: heap.append((-c, 'c'))
        import heapq
        heapq.heapify(heap)
        while heap:
            cnt, ch = heapq.heappop(heap)
            if len(res) >= 2 and res[-1] == ch and res[-2] == ch:
                if not heap:
                    break
                cnt2, ch2 = heapq.heappop(heap)
                res.append(ch2)
                cnt2 += 1
                if cnt2 != 0:
                    heapq.heappush(heap, (cnt2, ch2))
                heapq.heappush(heap, (cnt, ch))
            else:
                res.append(ch)
                cnt += 1
                if cnt != 0:
                    heapq.heappush(heap, (cnt, ch))
        return ''.join(res)
