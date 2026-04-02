class Solution:
    def minCostToMoveChips(self, position: list[int]) -> int:
        even = sum(1 for p in position if p % 2 == 0)
        odd = len(position) - even
        return min(even, odd)
