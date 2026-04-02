class Solution:
    def luckyNumbers(self, matrix: list[list[int]]) -> list[int]:
        min_rows = {min(row) for row in matrix}
        max_cols = {max(col) for col in zip(*matrix)}
        return list(min_rows & max_cols)
