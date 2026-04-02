from typing import List


class Solution:
    def maximumPoints(self, enemyEnergies: List[int], currentEnergy: int) -> int:
        enemyEnergies.sort()
        if currentEnergy < enemyEnergies[0]:
            return 0
        total = currentEnergy + sum(enemyEnergies[1:])
        return total // enemyEnergies[0]
