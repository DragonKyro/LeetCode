from typing import List


class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        mat = [[0] * (n + 1) for _ in range(n + 1)]
        for r1, c1, r2, c2 in queries:
            for r in range(r1, r2 + 1):
                mat[r][c1] += 1
                if c2 + 1 < n:
                    mat[r][c2 + 1] -= 1
        res = [[0] * n for _ in range(n)]
        for r in range(n):
            s = 0
            for c in range(n):
                s += mat[r][c]
                res[r][c] = s
        return res
