from typing import List


class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        has_incoming = set()
        for _, to in edges:
            has_incoming.add(to)
        return [i for i in range(n) if i not in has_incoming]
