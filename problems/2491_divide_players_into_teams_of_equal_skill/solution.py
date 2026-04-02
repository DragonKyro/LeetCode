from typing import List


class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        target = skill[0] + skill[-1]
        chemistry = 0
        for i in range(len(skill) // 2):
            if skill[i] + skill[-(i+1)] != target:
                return -1
            chemistry += skill[i] * skill[-(i+1)]
        return chemistry
