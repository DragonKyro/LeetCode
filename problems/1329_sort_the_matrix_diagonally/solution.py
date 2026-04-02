class Solution:
    def diagonalSort(self, mat: list[list[int]]) -> list[list[int]]:
        m, n = len(mat), len(mat[0])
        from collections import defaultdict
        d: dict[int, list[int]] = defaultdict(list)
        for i in range(m):
            for j in range(n):
                d[i - j].append(mat[i][j])
        for key in d:
            d[key].sort(reverse=True)
        for i in range(m):
            for j in range(n):
                mat[i][j] = d[i - j].pop()
        return mat
