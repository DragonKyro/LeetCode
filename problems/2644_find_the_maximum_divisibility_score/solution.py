from typing import List


class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        best_d, best_cnt = divisors[0], -1
        for d in divisors:
            cnt = sum(1 for n in nums if n % d == 0)
            if cnt > best_cnt or (cnt == best_cnt and d < best_d):
                best_d, best_cnt = d, cnt
        return best_d
