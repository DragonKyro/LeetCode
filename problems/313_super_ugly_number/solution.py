class Solution:
    def nthSuperUglyNumber(self, n: int, primes: list[int]) -> int:
        import heapq
        ugly = [1]
        heap = [(p, 0, p) for p in primes]
        heapq.heapify(heap)
        while len(ugly) < n:
            val, idx, prime = heapq.heappop(heap)
            if val != ugly[-1]:
                ugly.append(val)
            heapq.heappush(heap, (prime * ugly[idx + 1], idx + 1, prime))
        return ugly[-1]
