from typing import List


class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        import heapq
        indexed = sorted(range(len(tasks)), key=lambda i: tasks[i][0])
        result = []
        heap = []
        time = 0
        i = 0
        while i < len(indexed) or heap:
            if not heap and i < len(indexed) and tasks[indexed[i]][0] > time:
                time = tasks[indexed[i]][0]
            while i < len(indexed) and tasks[indexed[i]][0] <= time:
                idx = indexed[i]
                heapq.heappush(heap, (tasks[idx][1], idx))
                i += 1
            proc_time, idx = heapq.heappop(heap)
            time += proc_time
            result.append(idx)
        return result
