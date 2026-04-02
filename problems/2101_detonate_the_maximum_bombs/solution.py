class Solution:
    def maximumDetonation(self, bombs: list[list[int]]) -> int:
        n = len(bombs)
        graph: list[list[int]] = [[] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i != j:
                    dx = bombs[i][0] - bombs[j][0]
                    dy = bombs[i][1] - bombs[j][1]
                    if dx * dx + dy * dy <= bombs[i][2] * bombs[i][2]:
                        graph[i].append(j)
        def bfs(start: int) -> int:
            visited = {start}
            queue = [start]
            while queue:
                node = queue.pop(0)
                for nei in graph[node]:
                    if nei not in visited:
                        visited.add(nei)
                        queue.append(nei)
            return len(visited)
        return max(bfs(i) for i in range(n))
