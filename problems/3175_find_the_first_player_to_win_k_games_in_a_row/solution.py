from typing import List


class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        n = len(skills)
        wins = 0
        curr = 0
        for i in range(1, n):
            if skills[curr] > skills[i]:
                wins += 1
            else:
                curr = i
                wins = 1
            if wins >= k:
                return curr
        return curr
