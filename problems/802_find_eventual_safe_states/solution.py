from typing import List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        color = [0] * n
        def dfs(node: int) -> bool:
            if color[node] != 0:
                return color[node] == 2
            color[node] = 1
            for nei in graph[node]:
                if not dfs(nei):
                    return False
            color[node] = 2
            return True
        return [i for i in range(n) if dfs(i)]
