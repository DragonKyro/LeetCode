from typing import List


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        res = 0
        prefix = 0
        for s in satisfaction:
            prefix += s
            if prefix <= 0:
                break
            res += prefix
        return res
