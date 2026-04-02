from typing import List


class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        graph = defaultdict(list)
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
        self.fuel = 0
        def dfs(node: int, parent: int) -> int:
            people = 1
            for neighbor in graph[node]:
                if neighbor != parent:
                    people += dfs(neighbor, node)
            if node != 0:
                self.fuel += ceil(people / seats)
            return people
        dfs(0, -1)
        return self.fuel
