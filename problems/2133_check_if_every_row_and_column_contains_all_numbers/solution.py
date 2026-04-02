class Solution:
    def checkValid(self, matrix: list[list[int]]) -> bool:
        n = len(matrix)
        for row in matrix:
            if len(set(row)) != n:
                return False
        for j in range(n):
            col = set()
            for i in range(n):
                col.add(matrix[i][j])
            if len(col) != n:
                return False
        return True
