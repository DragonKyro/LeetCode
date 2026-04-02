from typing import Dict, List


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        parent: Dict[int, int] = {}

        def find(x: int) -> int:
            if x not in parent:
                parent[x] = x
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        for r, c in stones:
            union(r, ~c)
        return len(stones) - len({find(r) for r, c in stones})
