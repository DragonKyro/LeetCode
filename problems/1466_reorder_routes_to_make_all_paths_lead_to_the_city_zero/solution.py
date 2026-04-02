from typing import List


class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        from collections import defaultdict, deque
        graph = defaultdict(list)
        roads = set()
        for a, b in connections:
            graph[a].append(b)
            graph[b].append(a)
            roads.add((a, b))
        visited = set([0])
        queue = deque([0])
        count = 0
        while queue:
            node = queue.popleft()
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    if (node, neighbor) in roads:
                        count += 1
                    queue.append(neighbor)
        return count
