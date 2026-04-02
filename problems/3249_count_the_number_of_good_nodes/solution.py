from typing import List


class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        res = 0
        def dfs(u, parent):
            nonlocal res
            sizes = []
            total = 1
            for v in g[u]:
                if v != parent:
                    sz = dfs(v, u)
                    sizes.append(sz)
                    total += sz
            if not sizes or len(set(sizes)) == 1:
                res += 1
            return total
        dfs(0, -1)
        return res
