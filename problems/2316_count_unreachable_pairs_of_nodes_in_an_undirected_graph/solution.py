from typing import List


class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        parent = list(range(n))
        size = [1] * n
        def find(x: int) -> int:
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(x: int, y: int) -> None:
            px, py = find(x), find(y)
            if px == py: return
            if size[px] < size[py]: px, py = py, px
            parent[py] = px
            size[px] += size[py]
        for u, v in edges:
            union(u, v)
        components = []
        for i in range(n):
            if find(i) == i:
                components.append(size[i])
        total = 0
        remaining = n
        for s in components:
            remaining -= s
            total += s * remaining
        return total
