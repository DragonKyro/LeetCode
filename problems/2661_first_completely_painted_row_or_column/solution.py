from typing import List


class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        pos = {}
        for r in range(m):
            for c in range(n):
                pos[mat[r][c]] = (r, c)
        row_cnt = [0] * m
        col_cnt = [0] * n
        for i, val in enumerate(arr):
            r, c = pos[val]
            row_cnt[r] += 1
            col_cnt[c] += 1
            if row_cnt[r] == n or col_cnt[c] == m:
                return i
        return -1
