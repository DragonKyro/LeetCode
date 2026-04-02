class Solution:
    def gardenNoAdj(self, n: int, paths: list[list[int]]) -> list[int]:
        graph = [[] for _ in range(n)]
        for u, v in paths:
            graph[u-1].append(v-1)
            graph[v-1].append(u-1)
        result = [0] * n
        for i in range(n):
            used = {result[j] for j in graph[i]}
            for color in range(1, 5):
                if color not in used:
                    result[i] = color
                    break
        return result
