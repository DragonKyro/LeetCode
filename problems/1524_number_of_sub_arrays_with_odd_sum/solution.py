from typing import List


class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        odd = 0
        even = 1
        prefix = 0
        res = 0
        for n in arr:
            prefix += n
            if prefix % 2 == 1:
                res = (res + even) % MOD
                odd += 1
            else:
                res = (res + odd) % MOD
                even += 1
        return res
