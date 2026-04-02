from typing import List


class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        from collections import Counter
        cnt = Counter(nums)
        res = 0
        for k, v in cnt.items():
            if v == 2:
                res ^= k
        return res
