from typing import List


class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        parent = list(range(len(strs)))
        def find(x: int) -> int:
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(x: int, y: int):
            px, py = find(x), find(y)
            if px != py:
                parent[px] = py
        def similar(a: str, b: str) -> bool:
            diff = 0
            for i in range(len(a)):
                if a[i] != b[i]:
                    diff += 1
                    if diff > 2:
                        return False
            return True
        for i in range(len(strs)):
            for j in range(i + 1, len(strs)):
                if similar(strs[i], strs[j]):
                    union(i, j)
        return len(set(find(i) for i in range(len(strs))))
