from typing import List


class Solution:
    def fillCups(self, amount: List[int]) -> int:
        result = 0
        while True:
            amount.sort()
            if amount[2] == 0:
                break
            if amount[1] == 0:
                result += amount[2]
                break
            amount[2] -= 1
            amount[1] -= 1
            result += 1
        return result
