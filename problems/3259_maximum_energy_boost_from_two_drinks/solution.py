from typing import List


class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        n = len(energyDrinkA)
        a = energyDrinkA[0]
        b = energyDrinkB[0]
        for i in range(1, n):
            na = max(a + energyDrinkA[i], b)
            nb = max(b + energyDrinkB[i], a)
            a, b = na, nb
        return max(a, b)
