from typing import List


class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        parent = list(range(n))
        rank = [0] * n
        cost = [(1 << 30) - 1] * n
        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(a, b, w):
            ra, rb = find(a), find(b)
            if ra == rb:
                cost[ra] &= w
                return
            if rank[ra] < rank[rb]:
                ra, rb = rb, ra
            parent[rb] = ra
            cost[ra] = cost[ra] & cost[rb] & w
            if rank[ra] == rank[rb]:
                rank[ra] += 1
        for u, v, w in edges:
            union(u, v, w)
        res = []
        for s, t in query:
            if s == t:
                res.append(0)
            elif find(s) != find(t):
                res.append(-1)
            else:
                res.append(cost[find(s)])
        return res
