from typing import List


class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        total = sum(machines)
        n = len(machines)
        if total % n != 0:
            return -1
        avg = total // n
        res = 0
        running_sum = 0
        for m in machines:
            diff = m - avg
            running_sum += diff
            res = max(res, abs(running_sum), diff)
        return res
