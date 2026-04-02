class Solution:
    def reorganizeString(self, s: str) -> str:
        counts = collections.Counter(s)
        max_heap = [(-cnt, ch) for ch, cnt in counts.items()]
        heapq.heapify(max_heap)
        result = []
        prev_cnt, prev_ch = 0, ''
        while max_heap:
            cnt, ch = heapq.heappop(max_heap)
            result.append(ch)
            if prev_cnt < 0:
                heapq.heappush(max_heap, (prev_cnt, prev_ch))
            prev_cnt, prev_ch = cnt + 1, ch
        return ''.join(result) if len(result) == len(s) else ''
