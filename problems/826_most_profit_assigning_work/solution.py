from typing import List


class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        worker.sort()
        result = 0
        best = 0
        j = 0
        for w in worker:
            while j < len(jobs) and jobs[j][0] <= w:
                best = max(best, jobs[j][1])
                j += 1
            result += best
        return result
