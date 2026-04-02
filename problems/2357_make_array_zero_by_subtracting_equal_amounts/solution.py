from typing import List


class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        non_zero = set(nums) - {0}
        return len(non_zero)
