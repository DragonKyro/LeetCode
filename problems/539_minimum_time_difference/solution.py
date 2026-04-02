from typing import List


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        minutes = sorted(int(t[:2]) * 60 + int(t[3:]) for t in timePoints)
        min_diff = 1440 - minutes[-1] + minutes[0]
        for i in range(1, len(minutes)):
            min_diff = min(min_diff, minutes[i] - minutes[i - 1])
        return min_diff
