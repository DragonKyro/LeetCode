class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: list[list[int]], blueEdges: list[list[int]]) -> list[int]:
        from collections import deque
        graph = [[[] for _ in range(n)] for _ in range(2)]
        for u, v in redEdges:
            graph[0][u].append(v)
        for u, v in blueEdges:
            graph[1][u].append(v)
        result = [-1] * n
        visited = [[False] * n for _ in range(2)]
        queue = deque([(0, 0, 0), (0, 1, 0)])
        visited[0][0] = True
        visited[1][0] = True
        while queue:
            node, color, dist = queue.popleft()
            if result[node] == -1:
                result[node] = dist
            next_color = 1 - color
            for neighbor in graph[next_color][node]:
                if not visited[next_color][neighbor]:
                    visited[next_color][neighbor] = True
                    queue.append((neighbor, next_color, dist + 1))
        return result
