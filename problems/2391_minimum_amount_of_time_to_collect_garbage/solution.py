from typing import List


class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        result = 0
        last = {'M': 0, 'P': 0, 'G': 0}
        for i, g in enumerate(garbage):
            result += len(g)
            for c in g:
                last[c] = i
        prefix = list(accumulate(travel, initial=0))
        for v in last.values():
            result += prefix[v]
        return result
