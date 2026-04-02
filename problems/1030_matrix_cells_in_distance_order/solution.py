class Solution:
    def allCellsDistOrder(self, rows: int, cols: int, rCenter: int, cCenter: int) -> list[list[int]]:
        cells = [[i, j] for i in range(rows) for j in range(cols)]
        cells.sort(key=lambda c: abs(c[0] - rCenter) + abs(c[1] - cCenter))
        return cells
