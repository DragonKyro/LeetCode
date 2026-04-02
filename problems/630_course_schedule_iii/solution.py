class Solution:
    def scheduleCourse(self, courses: list[list[int]]) -> int:
        import heapq
        courses.sort(key=lambda x: x[1])
        heap = []
        time = 0
        for duration, deadline in courses:
            time += duration
            heapq.heappush(heap, -duration)
            if time > deadline:
                time += heapq.heappop(heap)
        return len(heap)
