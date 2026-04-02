from typing import List


class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        count = Counter(nums)
        return sum(k for k, v in count.items() if v == 1)
