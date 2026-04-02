class Solution:
    def findRedundantDirectedConnection(self, edges: list[list[int]]) -> list[int]:
        n = len(edges)
        parent = [0] * (n + 1)
        cand1 = cand2 = None
        for u, v in edges:
            if parent[v] != 0:
                cand1 = [parent[v], v]
                cand2 = [u, v]
                break
            parent[v] = u
        root = list(range(n + 1))
        def find(x):
            while root[x] != x:
                root[x] = root[root[x]]
                x = root[x]
            return x
        for u, v in edges:
            if cand2 and u == cand2[0] and v == cand2[1]:
                continue
            pu, pv = find(u), find(v)
            if pu == pv:
                return cand1 if cand1 else [u, v]
            root[pv] = pu
        return cand2
