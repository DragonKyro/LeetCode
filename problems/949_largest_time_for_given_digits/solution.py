from typing import List


class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        from itertools import permutations
        result = -1
        for h1, h2, m1, m2 in permutations(arr):
            hours = h1 * 10 + h2
            minutes = m1 * 10 + m2
            if hours < 24 and minutes < 60:
                result = max(result, hours * 60 + minutes)
        if result == -1:
            return ''
        return f'{result // 60:02d}:{result % 60:02d}'
