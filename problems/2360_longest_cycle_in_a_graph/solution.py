from typing import List


class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        visited = [0] * n
        result = -1
        time = 1
        for i in range(n):
            if visited[i] > 0:
                continue
            start_time = time
            node = i
            while node != -1 and visited[node] == 0:
                visited[node] = time
                time += 1
                node = edges[node]
            if node != -1 and visited[node] >= start_time:
                result = max(result, time - visited[node])
        return result
