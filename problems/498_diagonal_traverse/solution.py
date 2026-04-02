from typing import List


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat:
            return []
        m, n = len(mat), len(mat[0])
        result = []
        r, c = 0, 0
        going_up = True
        while len(result) < m * n:
            result.append(mat[r][c])
            if going_up:
                if c == n - 1:
                    r += 1
                    going_up = False
                elif r == 0:
                    c += 1
                    going_up = False
                else:
                    r -= 1
                    c += 1
            else:
                if r == m - 1:
                    c += 1
                    going_up = True
                elif c == 0:
                    r += 1
                    going_up = True
                else:
                    r += 1
                    c -= 1
        return result
