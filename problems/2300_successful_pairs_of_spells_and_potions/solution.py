from typing import List


class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(potions)
        result = []
        for spell in spells:
            left, right = 0, n
            while left < right:
                mid = (left + right) // 2
                if spell * potions[mid] >= success:
                    right = mid
                else:
                    left = mid + 1
            result.append(n - left)
        return result
