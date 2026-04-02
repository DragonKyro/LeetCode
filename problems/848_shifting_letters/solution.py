from typing import List


class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n = len(shifts)
        total = 0
        result = list(s)
        for i in range(n - 1, -1, -1):
            total += shifts[i]
            result[i] = chr((ord(s[i]) - ord('a') + total) % 26 + ord('a'))
        return ''.join(result)
