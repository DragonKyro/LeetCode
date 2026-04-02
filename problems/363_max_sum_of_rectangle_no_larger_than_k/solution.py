class Solution:
    def maxSumSubmatrix(self, matrix: list[list[int]], k: int) -> int:
        from sortedcontainers import SortedList
        m, n = len(matrix), len(matrix[0])
        res = float('-inf')
        for left in range(n):
            row_sum = [0] * m
            for right in range(left, n):
                for i in range(m):
                    row_sum[i] += matrix[i][right]
                sl = SortedList([0])
                prefix = 0
                for s in row_sum:
                    prefix += s
                    idx = sl.bisect_left(prefix - k)
                    if idx < len(sl):
                        res = max(res, prefix - sl[idx])
                    sl.add(prefix)
        return res
