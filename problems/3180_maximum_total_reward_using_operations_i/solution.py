from typing import List


class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues = sorted(set(rewardValues))
        dp = {0}
        for v in rewardValues:
            new_dp = set()
            for x in dp:
                if x < v:
                    new_dp.add(x + v)
            dp |= new_dp
        return max(dp)
