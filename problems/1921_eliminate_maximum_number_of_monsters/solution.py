from typing import List


class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        import math
        times = sorted(math.ceil(d / s) for d, s in zip(dist, speed))
        for i in range(len(times)):
            if times[i] <= i:
                return i
        return len(times)
