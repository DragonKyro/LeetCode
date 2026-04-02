from typing import List


class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def is_magic(r: int, c: int) -> bool:
            vals = set()
            for i in range(3):
                for j in range(3):
                    v = grid[r+i][c+j]
                    if v < 1 or v > 9:
                        return False
                    vals.add(v)
            if len(vals) != 9:
                return False
            for i in range(3):
                if sum(grid[r+i][c+j] for j in range(3)) != 15:
                    return False
                if sum(grid[r+j][c+i] for j in range(3)) != 15:
                    return False
            if grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15:
                return False
            if grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15:
                return False
            return True
        m, n = len(grid), len(grid[0])
        return sum(is_magic(r, c) for r in range(m - 2) for c in range(n - 2))
