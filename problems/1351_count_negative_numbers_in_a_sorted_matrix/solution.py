class Solution:
    def countNegatives(self, grid: list[list[int]]) -> int:
        count = 0
        for row in grid:
            for x in row:
                if x < 0:
                    count += 1
        return count
