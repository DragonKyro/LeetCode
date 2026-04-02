class Solution:
    def longestIncreasingPath(self, matrix: list[list[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        memo = {}
        def dfs(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            best = 1
            for di, dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < m and 0 <= nj < n and matrix[ni][nj] > matrix[i][j]:
                    best = max(best, 1 + dfs(ni, nj))
            memo[(i, j)] = best
            return best
        return max(dfs(i, j) for i in range(m) for j in range(n))
