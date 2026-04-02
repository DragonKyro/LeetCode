from typing import List


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        min_prefix = 0
        prefix = 0
        for n in nums:
            prefix += n
            min_prefix = min(min_prefix, prefix)
        return 1 - min_prefix
