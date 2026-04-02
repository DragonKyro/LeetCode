from typing import List


class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        def score(p):
            s = 0
            for i in range(len(p)):
                mult = 2 if (i >= 1 and p[i-1] == 10) or (i >= 2 and p[i-2] == 10) else 1
                s += mult * p[i]
            return s
        s1, s2 = score(player1), score(player2)
        if s1 > s2: return 1
        if s2 > s1: return 2
        return 0
