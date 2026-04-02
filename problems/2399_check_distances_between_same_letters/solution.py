from typing import List


class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        first = {}
        for i, c in enumerate(s):
            if c in first:
                if i - first[c] - 1 != distance[ord(c) - ord('a')]:
                    return False
            else:
                first[c] = i
        return True
