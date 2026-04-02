from typing import List


class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])
        lo, hi = 0, m - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            max_col = max(range(n), key=lambda j: mat[mid][j])
            above = mat[mid - 1][max_col] if mid > 0 else -1
            below = mat[mid + 1][max_col] if mid < m - 1 else -1
            if mat[mid][max_col] > above and mat[mid][max_col] > below:
                return [mid, max_col]
            elif above > mat[mid][max_col]:
                hi = mid - 1
            else:
                lo = mid + 1
        return [-1, -1]
