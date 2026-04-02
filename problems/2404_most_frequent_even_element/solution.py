from typing import List


class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        count = Counter(x for x in nums if x % 2 == 0)
        if not count:
            return -1
        return min(count, key=lambda x: (-count[x], x))
