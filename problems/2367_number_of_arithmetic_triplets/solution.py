from typing import List


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        s = set(nums)
        return sum(1 for n in nums if n + diff in s and n + 2 * diff in s)
