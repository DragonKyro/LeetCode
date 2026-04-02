from typing import List


class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues = sorted(set(rewardValues))
        dp = 1
        for v in rewardValues:
            mask = (1 << v) - 1
            dp |= (dp & mask) << v
        return dp.bit_length() - 1
