from typing import List


class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        indices = [i for i, v in enumerate(nums) if v == x]
        return [indices[q - 1] if q <= len(indices) else -1 for q in queries]
