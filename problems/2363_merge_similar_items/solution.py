from typing import List


class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        merged = defaultdict(int)
        for v, w in items1:
            merged[v] += w
        for v, w in items2:
            merged[v] += w
        return sorted(merged.items())
