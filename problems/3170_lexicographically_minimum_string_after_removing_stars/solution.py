class Solution:
    def clearStars(self, s: str) -> str:
        import heapq
        heap = []
        removed = set()
        for i, c in enumerate(s):
            if c == '*':
                removed.add(i)
                ch, neg_idx = heapq.heappop(heap)
                removed.add(-neg_idx)
            else:
                heapq.heappush(heap, (c, -i))
        return ''.join(s[i] for i in range(len(s)) if i not in removed)
