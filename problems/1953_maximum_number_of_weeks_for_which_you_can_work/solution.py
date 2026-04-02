from typing import List


class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        total = sum(milestones)
        max_val = max(milestones)
        rest = total - max_val
        if max_val > rest + 1:
            return 2 * rest + 1
        return total
