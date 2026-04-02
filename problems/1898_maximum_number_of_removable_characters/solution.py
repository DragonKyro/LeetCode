from typing import List


class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        def canRemove(k: int) -> bool:
            removed = set(removable[:k])
            j = 0
            for i in range(len(s)):
                if i in removed:
                    continue
                if j < len(p) and s[i] == p[j]:
                    j += 1
            return j == len(p)
        lo, hi = 0, len(removable)
        while lo <= hi:
            mid = (lo + hi) // 2
            if canRemove(mid):
                lo = mid + 1
            else:
                hi = mid - 1
        return hi
