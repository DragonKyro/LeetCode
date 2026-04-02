from typing import List


class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for a, b in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        color = {}
        def bfs(node: int) -> bool:
            queue = deque([node])
            color[node] = 0
            while queue:
                u = queue.popleft()
                for v in graph[u]:
                    if v in color:
                        if color[v] == color[u]:
                            return False
                    else:
                        color[v] = 1 - color[u]
                        queue.append(v)
            return True
        for i in range(1, n + 1):
            if i not in color:
                if not bfs(i):
                    return False
        return True
