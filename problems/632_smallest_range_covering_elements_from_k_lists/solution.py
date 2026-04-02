class Solution:
    def smallestRange(self, nums: list[list[int]]) -> list[int]:
        import heapq
        heap = []
        max_val = float('-inf')
        for i, row in enumerate(nums):
            heapq.heappush(heap, (row[0], i, 0))
            max_val = max(max_val, row[0])
        best = [float('-inf'), float('inf')]
        while True:
            min_val, i, j = heapq.heappop(heap)
            if max_val - min_val < best[1] - best[0]:
                best = [min_val, max_val]
            if j + 1 >= len(nums[i]):
                break
            nxt = nums[i][j + 1]
            max_val = max(max_val, nxt)
            heapq.heappush(heap, (nxt, i, j + 1))
        return best
