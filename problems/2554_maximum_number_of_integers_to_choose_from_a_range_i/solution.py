from typing import List


class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        b = set(banned)
        count = 0
        total = 0
        for i in range(1, n + 1):
            if i not in b:
                if total + i > maxSum:
                    break
                total += i
                count += 1
        return count
