from typing import List


class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(2):
            for j in range(2):
                b = w = 0
                for di in range(2):
                    for dj in range(2):
                        if grid[i+di][j+dj] == 'B': b += 1
                        else: w += 1
                if b >= 3 or w >= 3:
                    return True
        return False
