from typing import List


class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        delta = [0] * 101
        for birth, death in logs:
            delta[birth - 1950] += 1
            delta[death - 1950] -= 1
        max_pop = 0
        max_year = 1950
        curr = 0
        for i in range(101):
            curr += delta[i]
            if curr > max_pop:
                max_pop = curr
                max_year = 1950 + i
        return max_year
