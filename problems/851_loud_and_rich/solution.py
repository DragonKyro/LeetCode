from typing import List


class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        graph = defaultdict(list)
        for a, b in richer:
            graph[b].append(a)
        answer = [-1] * n
        def dfs(node: int) -> int:
            if answer[node] != -1:
                return answer[node]
            answer[node] = node
            for nei in graph[node]:
                cand = dfs(nei)
                if quiet[cand] < quiet[answer[node]]:
                    answer[node] = cand
            return answer[node]
        for i in range(n):
            dfs(i)
        return answer
