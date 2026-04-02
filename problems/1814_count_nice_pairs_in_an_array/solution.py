from typing import List


class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        from collections import Counter
        MOD = 10**9 + 7
        def rev(x: int) -> int:
            return int(str(x)[::-1])
        count = Counter()
        result = 0
        for x in nums:
            diff = x - rev(x)
            result = (result + count[diff]) % MOD
            count[diff] += 1
        return result
