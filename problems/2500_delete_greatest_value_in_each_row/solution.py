from typing import List


class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        for row in grid:
            row.sort()
        result = 0
        for j in range(len(grid[0])):
            mx = 0
            for i in range(len(grid)):
                mx = max(mx, grid[i][j])
            result += mx
        return result
