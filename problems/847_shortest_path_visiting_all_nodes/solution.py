from typing import List


class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        target = (1 << n) - 1
        queue = deque()
        visited = set()
        for i in range(n):
            state = (i, 1 << i)
            queue.append((i, 1 << i, 0))
            visited.add(state)
        while queue:
            node, mask, dist = queue.popleft()
            if mask == target:
                return dist
            for nei in graph[node]:
                new_mask = mask | (1 << nei)
                if (nei, new_mask) not in visited:
                    visited.add((nei, new_mask))
                    queue.append((nei, new_mask, dist + 1))
        return -1
