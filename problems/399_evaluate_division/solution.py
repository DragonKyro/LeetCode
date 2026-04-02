class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]:
        from collections import defaultdict, deque
        graph = defaultdict(dict)
        for (a, b), val in zip(equations, values):
            graph[a][b] = val
            graph[b][a] = 1.0 / val
        def bfs(src, dst):
            if src not in graph or dst not in graph:
                return -1.0
            if src == dst:
                return 1.0
            visited = {src}
            queue = deque([(src, 1.0)])
            while queue:
                node, product = queue.popleft()
                if node == dst:
                    return product
                for neighbor, val in graph[node].items():
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, product * val))
            return -1.0
        return [bfs(a, b) for a, b in queries]
