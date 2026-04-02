from typing import List


class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        total = 0
        i = 0
        while i < len(colors):
            j = i
            group_sum = 0
            group_max = 0
            while j < len(colors) and colors[j] == colors[i]:
                group_sum += neededTime[j]
                group_max = max(group_max, neededTime[j])
                j += 1
            total += group_sum - group_max
            i = j
        return total
