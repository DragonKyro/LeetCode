class Solution:
    def criticalConnections(self, n: int, connections: list[list[int]]) -> list[list[int]]:
        graph = [[] for _ in range(n)]
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        disc = [-1] * n
        low = [-1] * n
        result = []
        self.timer = 0
        def dfs(u: int, parent: int) -> None:
            disc[u] = low[u] = self.timer
            self.timer += 1
            for v in graph[u]:
                if v == parent:
                    continue
                if disc[v] == -1:
                    dfs(v, u)
                    low[u] = min(low[u], low[v])
                    if low[v] > disc[u]:
                        result.append([u, v])
                else:
                    low[u] = min(low[u], disc[v])
        dfs(0, -1)
        return result
