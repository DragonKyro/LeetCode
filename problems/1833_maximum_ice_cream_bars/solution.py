from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        count = 0
        for c in costs:
            if coins >= c:
                coins -= c
                count += 1
            else:
                break
        return count
